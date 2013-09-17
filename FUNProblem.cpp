/* 
 * File:   FUNProblem.cpp
 * Author: marcio
 * 
 * Created on 29 de Agosto de 2013, 16:53
 */

#include "FUNProblem.h"
#include "FUNOperator.h"
#include "LinkerNodes.h"
#include "FUNCodification.h"
#include "FUNObjective.h"

FUNProblem::FUNProblem() {
}

FUNProblem::~FUNProblem() {
}

const char* FUNProblem::name() const{
    return "FUN";
}
const char* FUNProblem::description() const{
    return "nothing";
}
Codification* FUNProblem::NewCodification() throw(exception){
    return new FUNCodification(this);
}
Objective* FUNProblem::NewObjective() throw(exception){
    return new FUNObjective();
}
void FUNProblem::services(LinkerNodes *com) throw(exception){
    Problem::services(com);
    com->addf(&FUNOperator::obj);
}

