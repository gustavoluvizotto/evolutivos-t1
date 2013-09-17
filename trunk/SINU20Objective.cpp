/* 
 * File:   SINU20Objective.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "SINU20Objective.h"
#include "SINU20Codification.h"
#include <math.h>

#define DTOR(x)         (x*M_PI/180.0)
#define TROD(x)         (x*180.0/M_PI)

SINU20Objective::SINU20Objective() {
}

SINU20Objective::~SINU20Objective() {
}

void SINU20Objective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    SINU20Codification* codif = dynamic_cast<SINU20Codification*> (A);
    double param_A = 2.5;
    double param_B = 5.0;
    double param_z = 30.0;

    double prod1 = 1.0;
    double prod2 = 1.0;

    for (int i = 0; i < 20; i++) {
        prod1 *= sin(DTOR(codif->cromo[i] - param_z));
        prod2 *= sin(DTOR(param_B * (codif->cromo[i] - param_z)));
    }

    double fitness = -(param_A * prod1 + prod2);
    set(fitness);
}

Objective* SINU20Objective::New(Problem* mem) throw (exception) {
    return new SINU20Objective();
}
