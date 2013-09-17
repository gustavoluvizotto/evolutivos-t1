/* 
 * File:   MCPObjective.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "MCPObjective.h"
#include "MCPCodification.h"
#include <math.h>

MCPObjective::MCPObjective() {
}

MCPObjective::~MCPObjective() {
}

void MCPObjective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    MCPCodification* codif = dynamic_cast<MCPCodification*> (A);

    double x1 = codif->cromo[0];
    double x2 = codif->cromo[1];
    double x3 = codif->cromo[2];
    double x4 = codif->cromo[3];

    double fitness = pow(exp(x1) - x2, 4) + 100.0 * pow(x2 - x3, 6) +
            pow(tan(x3 - x4), 4) + pow(x1, 8);

    set(fitness);
}

Objective* MCPObjective::New(Problem* mem) throw (exception) {
    return new MCPObjective();
}
