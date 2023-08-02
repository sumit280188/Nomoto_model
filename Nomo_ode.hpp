#ifndef NOMO_ODE_HPP
#define NOMO_ODE_HPP

#include <iostream>
#include <vector>
#include <boost/numeric/odeint.hpp>

const float K = 1.0;
const float T = 0.4;
const float delta = 60.0;

using namespace boost::numeric::odeint;
typedef std::vector<double> state_type;
typedef runge_kutta_dopri5<state_type> rk5;

void my_system(const state_type &x, state_type &dxdt, const double t)
{
    double a = (-1 / T);
    double b = (K / T);
    dxdt[0] = (a * x[0]) + (b * delta);
}

#endif