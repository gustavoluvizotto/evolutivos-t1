/* 
 * File:   GaussianDistribution.h
 * Author: lcrespilho
 *
 * Created on September 13, 2013, 2:45 AM
 */

#ifndef GAUSSIANDISTRIBUTION_H
#define	GAUSSIANDISTRIBUTION_H

#include <boost/random.hpp>
#include <boost/random/normal_distribution.hpp>

class GaussianDistribution {
public:
    GaussianDistribution(double, double);
    virtual ~GaussianDistribution();
    double Sample();

private:
    boost::mt19937 *rng;
    boost::normal_distribution<double> *nd;
    boost::variate_generator < boost::mt19937&, boost::normal_distribution<double> > *var_nor;
};

#endif	/* GAUSSIANDISTRIBUTION_H */