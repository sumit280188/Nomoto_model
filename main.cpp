#include "Nomo_ode.hpp"
#include "Nomo_obs.hpp"
#include "Nomo_sim.hpp"
#include <boost/math/interpolators/cubic_b_spline.hpp>
#include <boost/math/differentiation/finite_difference.hpp>
#include <cmath>

int main()
{

    std::vector<double> last_yaw;
    std::vector<double> last_velo;
    std::vector<double> last_x_pos;
    std::vector<double> last_y_pos;
    std::vector<double> last_yaw_rate;

    double t, x, y, yaw, yaw_rate;

    varSim vs = vS();
    state_type x0(1);
    x0[0] = 0.0;

    std::vector<state_type> x_vec;
    std::vector<double> times;

    size_t steps = integrate_adaptive(rk5(), my_system, x0, 0.0, vs.time, vs.step, my_observer(x_vec, times));

    resultNomo res;

    for (size_t i = 0; i <= steps; i++)
    {
        res.yaw_rate.push_back(x_vec[i][0]);
        res.time.push_back(times.at(i));

        if (i == 0)
        {
            res.yaw.push_back(0.0);
            res.yaw_acc.push_back(0.0);
            res.x_pos.push_back(0.0);
            res.y_pos.push_back(0.0);
        }
        else
        {
            double delta_time = res.time.at(i) - res.time.at(i - 1);

            double yaw = res.yaw_rate.at(i) * delta_time + res.yaw.at(i - 1);
            res.yaw.push_back(yaw);

            double yaw_acc = (res.yaw_rate.at(i) - res.yaw_rate.at(i - 1)) / delta_time;
            res.yaw_acc.push_back(yaw_acc);

            double yaw_rad = yaw * M_PI / 180;

            double x_pos = cos(yaw_rad) * delta_time * vs.velocity;
            res.x_pos.push_back(x_pos + res.x_pos.at(i - 1));

            double y_pos = sin(yaw_rad) * delta_time * vs.velocity;
            res.y_pos.push_back(y_pos + res.y_pos.at(i - 1));
        }
    }

    for (size_t i = 1; i < res.time.size(); i++)
    {
        t = (res.time.at(i));
        x = (res.x_pos.at(i));
        y = (res.y_pos.at(i));
        yaw = ((res.yaw.at(i)) * (M_PI / 180));
        yaw_rate = (res.yaw_rate.at(i) * (M_PI / 180));

        std::cout << "t[sec]: " << t << " x[m]: " << x << " y[m]: " << y << " yaw[deg]: " << yaw << " yaw_rate[deg/sec]: " << yaw_rate << '\n'
                  << '\n';

        last_yaw.push_back(yaw);
        last_velo.push_back(vs.velocity);
        last_x_pos.push_back(x);
        last_y_pos.push_back(y);
        last_yaw_rate.push_back(yaw_rate);
    }
}
