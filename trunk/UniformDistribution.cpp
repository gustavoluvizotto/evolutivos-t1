/* 
 * File:   UniformDistribution.cpp
 * Author: lcrespilho
 * 
 * Created on September 13, 2013, 2:45 AM
 */

#include "UniformDistribution.h"

UniformDistribution::UniformDistribution(double lower_bound, double upper_bound) {
    rng = new boost::mt19937;
    rng->seed();
    ud = new boost::uniform_real<double>(lower_bound, upper_bound);
    var_uni = new boost::variate_generator < boost::mt19937&, boost::uniform_real<double > > (*rng, *ud);
}

UniformDistribution::~UniformDistribution() {
    delete var_uni;
    delete ud;
    delete rng;
}

double UniformDistribution::Sample() {
    return (*var_uni)();
}