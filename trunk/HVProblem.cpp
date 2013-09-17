/* 
 * File:   HVProblem.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "HVProblem.h"
#include "HVCodification.h"
#include "HVObjective.h"
#include "LinkerNodes.h"
#include "HVOperator.h"

HVProblem::HVProblem() {
}

HVProblem::~HVProblem() {
}

const char* HVProblem::name() const{
    return "HV";
}
const char* HVProblem::description() const{
    return NULL;
}
Codification* HVProblem::NewCodification() throw(exception){
    return new HVCodification();
}
Objective* HVProblem::NewObjective() throw(exception){
    return new HVObjective();
}
void HVProblem::services(LinkerNodes *com) throw(exception){
    com->addf(&HVOperator::obj);
}