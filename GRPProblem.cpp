/* 
 * File:   GRPProblem.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "GRPProblem.h"
#include "GRPCodification.h"
#include "GRPObjective.h"
#include "LinkerNodes.h"
#include "GRPOperator.h"

GRPProblem::GRPProblem() {
}

GRPProblem::~GRPProblem() {
}

const char* GRPProblem::name() const{
    return "GRP";
}
const char* GRPProblem::description() const{
    return NULL;
}
Codification* GRPProblem::NewCodification() throw(exception){
    return new GRPCodification();
}
Objective* GRPProblem::NewObjective() throw(exception){
    return new GRPObjective();
}
void GRPProblem::services(LinkerNodes *com) throw(exception){
    com->addf(&GRPOperator::obj);
}
