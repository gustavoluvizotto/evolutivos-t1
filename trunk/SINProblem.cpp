/* 
 * File:   SINProblem.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "SINProblem.h"
#include "SINCodification.h"
#include "SINObjective.h"
#include "LinkerNodes.h"
#include "SINOperator.h"

SINProblem::SINProblem() {
}

SINProblem::~SINProblem() {
}

const char* SINProblem::name() const {
    return "SIN";
}

const char* SINProblem::description() const {
    return NULL;
}

Codification* SINProblem::NewCodification() throw (exception) {
    return new SINCodification();
}

Objective* SINProblem::NewObjective() throw (exception) {
    return new SINObjective();
}

void SINProblem::services(LinkerNodes *com) throw (exception) {
    com->addf(&SINOperator::obj);
}
