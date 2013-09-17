/* 
 * File:   UniformDistribution.h
 * Author: lcrespilho
 *
 * Created on September 13, 2013, 2:45 AM
 */

#ifndef GAUSSIANDISTRIBUTION_H
#define	GAUSSIANDISTRIBUTION_H

#include <boost/random.hpp>
#include <boost/random/normal_distribution.hpp>

class UniformDistribution {
public:
    UniformDistribution(double, double);
    virtual ~UniformDistribution();
    double Sample();

private:
    boost::mt19937 *rng;
    boost::uniform_real<double> *ud;
    boost::variate_generator < boost::mt19937&, boost::uniform_real<double> > *var_uni;
};

#endif	/* GAUSSIANDISTRIBUTION_H */

