/* 
 * File:   MCPProblem.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "MCPProblem.h"
#include "MCPCodification.h"
#include "MCPObjective.h"
#include "LinkerNodes.h"
#include "MCPOperator.h"

MCPProblem::MCPProblem() {
}

MCPProblem::~MCPProblem() {
}

const char* MCPProblem::name() const {
    return "MCP";
}

const char* MCPProblem::description() const {
    return NULL;
}

Codification* MCPProblem::NewCodification() throw (exception) {
    return new MCPCodification();
}

Objective* MCPProblem::NewObjective() throw (exception) {
    return new MCPObjective();
}

void MCPProblem::services(LinkerNodes *com) throw (exception) {
    com->addf(&MCPOperator::obj);
}