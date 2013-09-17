/* 
 * File:   LM2Problem.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "LM2Problem.h"
#include "LM2Codification.h"
#include "LM2Objective.h"
#include "LinkerNodes.h"
#include "LM2Operator.h"

LM2Problem::LM2Problem() {
}

LM2Problem::~LM2Problem() {
}

const char* LM2Problem::name() const{
    return "LM2";
}
const char* LM2Problem::description() const{
    return NULL;
}
Codification* LM2Problem::NewCodification() throw(exception){
    return new LM2Codification();
}
Objective* LM2Problem::NewObjective() throw(exception){
    return new LM2Objective();
}
void LM2Problem::services(LinkerNodes *com) throw(exception){
    com->addf(&LM2Operator::obj);
}