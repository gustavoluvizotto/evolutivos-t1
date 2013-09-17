/* 
 * File:   SINU20Problem.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "SINU20Problem.h"
#include "SINU20Codification.h"
#include "SINU20Objective.h"
#include "LinkerNodes.h"
#include "SINU20Operator.h"

SINU20Problem::SINU20Problem() {
}

SINU20Problem::~SINU20Problem() {
}

const char* SINU20Problem::name() const {
    return "SINU20";
}

const char* SINU20Problem::description() const {
    return NULL;
}

Codification* SINU20Problem::NewCodification() throw (exception) {
    return new SINU20Codification();
}

Objective* SINU20Problem::NewObjective() throw (exception) {
    return new SINU20Objective();
}

void SINU20Problem::services(LinkerNodes *com) throw (exception) {
    com->addf(&SINU20Operator::obj);
}
