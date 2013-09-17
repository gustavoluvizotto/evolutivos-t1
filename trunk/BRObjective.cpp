/* 
 * File:   BRObjective.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "BRObjective.h"
#include "BRCodification.h"
#include <math.h>

BRObjective::BRObjective() {
}

BRObjective::~BRObjective() {
}

void BRObjective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    BRCodification* codif = dynamic_cast<BRCodification*> (A);

    double a = 1.0, b = 5.1 / (4 * M_PI * M_PI), c = 5.0 / M_PI, d = 6.0, g = 10.0, h = 1.0 / (8 * M_PI);

    double fitness = a * pow(codif->cromo[1] - b * pow(codif->cromo[0], 2) + c * codif->cromo[0] - d, 2) +
            g * (1 - h) * cos(codif->cromo[0]) + g;

    set(fitness);
}

Objective* BRObjective::New(Problem* mem) throw (exception) {
    return new BRObjective();
}
