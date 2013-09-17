/* 
 * File:   ACKProblem.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "ACKProblem.h"
#include "ACKCodification.h"
#include "ACKObjective.h"
#include "LinkerNodes.h"
#include "ACKOperator.h"

ACKProblem::ACKProblem() {
}

ACKProblem::~ACKProblem() {
}

const char* ACKProblem::name() const {
    return "ACK";
}

const char* ACKProblem::description() const {
    return NULL;
}

Codification* ACKProblem::NewCodification() throw (exception) {
    return new ACKCodification();
}

Objective* ACKProblem::NewObjective() throw (exception) {
    return new ACKObjective();
}

void ACKProblem::services(LinkerNodes *com) throw (exception) {
    com->addf(&ACKOperator::obj);
}
