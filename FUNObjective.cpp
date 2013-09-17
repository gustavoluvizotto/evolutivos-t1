/* 
 * File:   FUNObjective.cpp
 * Author: marcio
 * 
 * Created on 29 de Agosto de 2013, 16:59
 */

#include "FUNObjective.h"

#include "FUNProblem.h"
#include "FUNCodification.h"

FUNObjective::FUNObjective() {
}
FUNObjective::~FUNObjective() {
}

void FUNObjective::Evaluate(Problem* prob, Codification* codif_a) throw(exception){
    FUNCodification* codif = dynamic_cast<FUNCodification*>(codif_a);
    double fitness = codif->x*codif->x;
    set(fitness);
}
   
Objective* FUNObjective::New(Problem* mem) throw(exception){
    return new FUNObjective();
}

