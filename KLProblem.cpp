/* 
 * File:   KLProblem.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "KLProblem.h"
#include "KLCodification.h"
#include "KLObjective.h"
#include "LinkerNodes.h"
#include "KLOperator.h"

KLProblem::KLProblem() {
}

KLProblem::~KLProblem() {
}

const char* KLProblem::name() const {
    return "KL";
}

const char* KLProblem::description() const {
    return NULL;
}

Codification* KLProblem::NewCodification() throw (exception) {
    return new KLCodification();
}

Objective* KLProblem::NewObjective() throw (exception) {
    return new KLObjective();
}

void KLProblem::services(LinkerNodes *com) throw (exception) {
    com->addf(&KLOperator::obj);
}