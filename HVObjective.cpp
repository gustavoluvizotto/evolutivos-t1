/* 
 * File:   HVObjective.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "HVObjective.h"
#include "HVCodification.h"
#include <math.h>

HVObjective::HVObjective() {
}

HVObjective::~HVObjective() {
}

void HVObjective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    HVCodification* codif = dynamic_cast<HVCodification*> (A);

    double x1 = codif->cromo[0];
    double x2 = codif->cromo[1];
    double x3 = codif->cromo[2];
    double theta;

    if (x1 >= 0)
        theta = atan2(x2, x1) / (2.0 * M_PI);
    else
        theta = atan2(x2, x1) / (2.0 * M_PI) + 0.5;

    double fitness = 100.0 * (pow(x2 - 10 * theta, 2) +
            pow(sqrt(pow(x1, 2) + pow(x2, 2)) - 1, 2)) + pow(x3, 2);
    set(fitness);
}

Objective* HVObjective::New(Problem* mem) throw (exception) {
    return new HVObjective();
}
