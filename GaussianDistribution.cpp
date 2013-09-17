/* 
 * File:   GaussianDistribution.cpp
 * Author: lcrespilho
 * 
 * Created on September 13, 2013, 2:45 AM
 */

#include "GaussianDistribution.h"

GaussianDistribution::GaussianDistribution(double media, double desviopadrao) {
    rng = new boost::mt19937;
    rng->seed();
    nd = new boost::normal_distribution<double>(media, desviopadrao);
    var_nor = new boost::variate_generator < boost::mt19937&, boost::normal_distribution<double> >(*rng, *nd);
}

GaussianDistribution::~GaussianDistribution() {
    delete var_nor;
    delete nd;
    delete rng;
}

double GaussianDistribution::Sample() {
    return (*var_nor)();
}