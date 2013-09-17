/* 
 * File:   GPProblem.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "GPProblem.h"
#include "GPCodification.h"
#include "GPObjective.h"
#include "LinkerNodes.h"
#include "GPOperator.h"

GPProblem::GPProblem() {
}

GPProblem::~GPProblem() {
}

const char* GPProblem::name() const{
    return "GP";
}
const char* GPProblem::description() const{
    return NULL;
}
Codification* GPProblem::NewCodification() throw(exception){
    return new GPCodification();
}
Objective* GPProblem::NewObjective() throw(exception){
    return new GPObjective();
}
void GPProblem::services(LinkerNodes *com) throw(exception){
    com->addf(&GPOperator::obj);
}
