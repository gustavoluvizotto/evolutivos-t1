/* 
 * File:   MRProblem.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "MRProblem.h"
#include "MRCodification.h"
#include "MRObjective.h"
#include "LinkerNodes.h"
#include "MROperator.h"

MRProblem::MRProblem() {
}

MRProblem::~MRProblem() {
}

const char* MRProblem::name() const {
    return "MR";
}

const char* MRProblem::description() const {
    return NULL;
}

Codification* MRProblem::NewCodification() throw (exception) {
    return new MRCodification();
}

Objective* MRProblem::NewObjective() throw (exception) {
    return new MRObjective();
}

void MRProblem::services(LinkerNodes *com) throw (exception) {
    com->addf(&MROperator::obj);
}
