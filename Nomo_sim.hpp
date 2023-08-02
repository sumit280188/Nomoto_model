#ifndef NOMO_SIM_HPP
#define NOMO_SIM_HPP

#include <iostream>
#include <vector>

struct resultNomo
{
    std::vector<double> x_pos;
    std::vector<double> y_pos;
    std::vector<double> time;
    std::vector<double> yaw;
    std::vector<double> yaw_rate;
    std::vector<double> yaw_acc;
};

struct varSim
{

    double velocity = 0;
    double initYaw = 0;
    double initYawRate = 0;
    double initX = 0;
    double initY = 0;
    double step = 0;
    double time = 0;
    bool terminal_output;
};
varSim vS();

#endif