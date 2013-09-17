/* 
 * File:   WPObjective.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "WPObjective.h"
#include "WPCodification.h"
#include <math.h>

WPObjective::WPObjective() {
}

WPObjective::~WPObjective() {
}

void WPObjective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    WPCodification* codif = dynamic_cast<WPCodification*> (A);

    double fitness = 100 * pow(codif->cromo[1] - pow(codif->cromo[0], 2), 2) +
            pow(1 - codif->cromo[0], 2) + 90 * pow(codif->cromo[3] - pow(codif->cromo[2], 2), 2) +
            pow(1 - codif->cromo[2], 2) + 10.1 *
            (pow(codif->cromo[1] - 1, 2) + pow(codif->cromo[3] - 1, 2)) +
            19.8 * (codif->cromo[1] - 1)*(codif->cromo[3] - 1);

    set(fitness);
}

Objective* WPObjective::New(Problem* mem) throw (exception) {
    return new WPObjective();
}
