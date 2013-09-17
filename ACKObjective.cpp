/* 
 * File:   ACKObjective.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "ACKObjective.h"
#include "ACKCodification.h"
#include <math.h>

ACKObjective::ACKObjective() {
}

ACKObjective::~ACKObjective() {
}

void ACKObjective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    ACKCodification* codif = dynamic_cast<ACKCodification*> (A);

    int n = 10;
    double sum1 = 0;
    double sum2 = 0;

    for (int i = 0; i < 10; i++) {
        sum1 += codif->cromo[i] * codif->cromo[i];
        sum2 += cos(2 * M_PI * codif->cromo[i]);
    }

    double fitness = -20 * exp(-0.02 * sqrt(sum1 / n)) - exp(sum2 / n) + 20 + exp(1);
//TODO: verificar o pq dessa coisa...
    if (fitness < 1e-6) fitness = 0;
    set(fitness);
}

Objective* ACKObjective::New(Problem* mem) throw (exception) {
    return new ACKObjective();
}
