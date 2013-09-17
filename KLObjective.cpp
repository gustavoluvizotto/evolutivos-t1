/* 
 * File:   KLObjective.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "KLObjective.h"
#include "KLCodification.h"
#include <math.h>

KLObjective::KLObjective() {
}

KLObjective::~KLObjective() {
}

void KLObjective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    KLCodification* codif = dynamic_cast<KLCodification*> (A);

    double x1 = codif->cromo[0];
    double x2 = codif->cromo[1];
    double x3 = codif->cromo[2];
    double x4 = codif->cromo[3];
    double a[] = {0.1957, 0.1947, 0.1735, 0.16, 0.0844, 0.0627, 0.0456, 0.0342, 0.0323, 0.0235, 0.0246};
    double b[] = {0.25, 0.50, 1.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0};
    double fitness = 0;

    for (int i = 0; i < 11; i++) {
        fitness += pow(a[i] - (x1 * (1 + x2 * b[i])) / (1 + x3 * b[i] + x4 * pow(b[i], 2)), 2);
    }

    set(fitness);
}

Objective* KLObjective::New(Problem* mem) throw (exception) {
    return new KLObjective();
}
