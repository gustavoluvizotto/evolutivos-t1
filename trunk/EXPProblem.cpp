/* 
 * File:   EXPProblem.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "EXPProblem.h"
#include "EXPCodification.h"
#include "EXPObjective.h"
#include "LinkerNodes.h"
#include "EXPOperator.h"

EXPProblem::EXPProblem() {
}

EXPProblem::~EXPProblem() {
}

const char* EXPProblem::name() const{
    return "EXP";
}
const char* EXPProblem::description() const{
    return NULL;
}
Codification* EXPProblem::NewCodification() throw(exception){
    return new EXPCodification();
}
Objective* EXPProblem::NewObjective() throw(exception){
    return new EXPObjective();
}
void EXPProblem::services(LinkerNodes *com) throw(exception){
    com->addf(&EXPOperator::obj);
}
