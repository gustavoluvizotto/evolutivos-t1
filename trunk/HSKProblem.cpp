/* 
 * File:   HSKProblem.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "HSKProblem.h"
#include "HSKCodification.h"
#include "HSKObjective.h"
#include "LinkerNodes.h"
#include "HSKOperator.h"

HSKProblem::HSKProblem() {
}

HSKProblem::~HSKProblem() {
}

const char* HSKProblem::name() const{
    return "HSK";
}
const char* HSKProblem::description() const{
    return NULL;
}
Codification* HSKProblem::NewCodification() throw(exception){
    return new HSKCodification();
}
Objective* HSKProblem::NewObjective() throw(exception){
    return new HSKObjective();
}
void HSKProblem::services(LinkerNodes *com) throw(exception){
    com->addf(&HSKOperator::obj);
}