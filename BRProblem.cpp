/* 
 * File:   BRProblem.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "BRProblem.h"
#include "BRCodification.h"
#include "BRObjective.h"
#include "LinkerNodes.h"
#include "BROperator.h"

BRProblem::BRProblem() {
}

BRProblem::~BRProblem() {
}

const char* BRProblem::name() const {
    return "BR";
}

const char* BRProblem::description() const {
    return NULL;
}

Codification* BRProblem::NewCodification() throw (exception) {
    return new BRCodification();
}

Objective* BRProblem::NewObjective() throw (exception) {
    return new BRObjective();
}

void BRProblem::services(LinkerNodes *com) throw (exception) {
    com->addf(&BROperator::obj);
}
