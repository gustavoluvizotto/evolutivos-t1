/* 
 * File:   CMProblem.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "CMProblem.h"
#include "CMCodification.h"
#include "CMObjective.h"
#include "LinkerNodes.h"
#include "CMOperator.h"

CMProblem::CMProblem() {
}

CMProblem::~CMProblem() {
}

const char* CMProblem::name() const{
    return "CM";
}
const char* CMProblem::description() const{
    return NULL;
}
Codification* CMProblem::NewCodification() throw(exception){
    return new CMCodification();
}
Objective* CMProblem::NewObjective() throw(exception){
    return new CMObjective();
}
void CMProblem::services(LinkerNodes *com) throw(exception){
    com->addf(&CMOperator::obj);
}
