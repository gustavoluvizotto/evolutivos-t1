/* 
 * File:   HSKObjective.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "HSKObjective.h"
#include "HSKCodification.h"
#include <math.h>

HSKObjective::HSKObjective() {
}

HSKObjective::~HSKObjective() {
}

void HSKObjective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    HSKCodification* codif = dynamic_cast<HSKCodification*> (A);

    double x1 = codif->cromo[0];
    double x2 = codif->cromo[1];

    double fitness = (1.0 - 8.0 * x1 + 7.0 * pow(x1, 2) - (7.0 / 3.0) * pow(x1, 3) + 
    pow(x1, 4) / 4.0) * pow(x2, 2) * exp(-x2);
    set(fitness);
}

Objective* HSKObjective::New(Problem* mem) throw (exception) {
    return new HSKObjective();
}
