/* 
 * File:   MRObjective.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "MRObjective.h"
#include "MRCodification.h"
#include <math.h>

MRObjective::MRObjective() {
}

MRObjective::~MRObjective() {
}

void MRObjective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    MRCodification* codif = dynamic_cast<MRCodification*> (A);
    double t[] = {1.0, 2.0, 1.0, 2.0, 0.1};
    double v[] = {1.0, 1.0, 2.0, 2.0, 0.0};
    double y[] = {0.126, 0.219, 0.076, 0.126, 0.186};
    double fitness = 0;
    for (int i = 0; i < 5; i++) {
        fitness += pow(codif->cromo[0] * codif->cromo[2] * t[i] / (1 + codif->cromo[0] * t[i] + codif->cromo[1] * v[i]) - y[i], 2);
    }

    set(fitness);
}

Objective* MRObjective::New(Problem* mem) throw (exception) {
    return new MRObjective();
}
