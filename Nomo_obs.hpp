#ifndef NOMO_OBS_HPP
#define NOMO_OBS_HPP

#include <iostream>
#include <vector>
#include "Nomo_ode.hpp"

typedef std::vector<double> state_type;

struct my_observer
{
    std::vector<state_type> &m_states;
    std::vector<double> &m_times;

    my_observer(std::vector<state_type> &states, std::vector<double> &times)
        : m_states(states), m_times(times) {}

    void operator()(const state_type &x, double t)
    {
        m_states.push_back(x);
        m_times.push_back(t);
    }
};
#endif