/* 
 * File:   LM2Objective.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "LM2Objective.h"
#include "LM2Codification.h"
#include <math.h>

LM2Objective::LM2Objective() {
}

LM2Objective::~LM2Objective() {
}

void LM2Objective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    LM2Codification* codif = dynamic_cast<LM2Codification*> (A);

    double sum = 0.0;
    for (int i = 0; i < 9; i++)
        sum += pow(codif->cromo[i] - 1.0, 2) * (1 + pow(sin(3 * M_PI * codif->cromo[i + 1]), 2));

    double fitness = 0.1 * (pow(sin(3 * M_PI * codif->cromo[0]), 2) + sum +
            pow(codif->cromo[9] - 1, 2) * (1 + pow(sin(2 * M_PI * codif->cromo[9]), 2)));
    set(fitness);
}

Objective* LM2Objective::New(Problem* mem) throw (exception) {
    return new LM2Objective();
}
