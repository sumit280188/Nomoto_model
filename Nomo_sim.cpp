#include <iostream>
#include <yaml-cpp/yaml.h>
#include "Nomo_sim.hpp"
#include <boost/math/interpolators/cubic_b_spline.hpp>
#include <boost/math/differentiation/finite_difference.hpp>

varSim vS()
{
    varSim var;
    YAML::Node config = YAML::LoadFile("./config.yaml");

    var.step = config["step"].as<double>();
    var.time = config["time"].as<double>();
    var.initYaw = config["initYaw"].as<double>();
    var.initYawRate = config["initYawRate"].as<double>();
    var.initX = config["initX"].as<double>();
    var.initY = config["initY"].as<double>();
    var.velocity = config["velocity"].as<double>();
    var.terminal_output = config["terminal_output"].as<bool>();

    return var;
}
