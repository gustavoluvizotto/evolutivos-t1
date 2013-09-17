/* 
 * File:   WPProblem.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "WPProblem.h"
#include "WPCodification.h"
#include "WPObjective.h"
#include "LinkerNodes.h"
#include "WPOperator.h"

WPProblem::WPProblem() {
}

WPProblem::~WPProblem() {
}

const char* WPProblem::name() const {
    return "WP";
}

const char* WPProblem::description() const {
    return NULL;
}

Codification* WPProblem::NewCodification() throw (exception) {
    return new WPCodification();
}

Objective* WPProblem::NewObjective() throw (exception) {
    return new WPObjective();
}

void WPProblem::services(LinkerNodes *com) throw (exception) {
    com->addf(&WPOperator::obj);
}
