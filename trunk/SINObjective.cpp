/* 
 * File:   SINObjective.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "SINObjective.h"
#include "SINCodification.h"
#include <cmath>

SINObjective::SINObjective() {
}

SINObjective::~SINObjective() {
}

void SINObjective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    SINCodification* codif = dynamic_cast<SINCodification*> (A);

    double x = decode(codif->cromo, 10, -1, +2);

    double fitness = x * sin(10 * M_PI * x) + 1;
    set(fitness);
}

Objective* SINObjective::New(Problem* mem) throw (exception) {
    return new SINObjective();
}

double SINObjective::decode(int *cromo, int tam, double min, double max) {
    double b10 = 0;
    double pot = 1;
    for (int i = 0; i < tam; i++) {
        b10 += cromo[i] * pot;
        pot = pot * 2;
    }
    return min + (max - min) * b10 / (pot - 1);
}
