/* 
 * File:   H6Problem.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:10
 */

#include "H6Problem.h"
#include "H6Codification.h"
#include "H6Objective.h"
#include "LinkerNodes.h"
#include "H6Operator.h"

H6Problem::H6Problem() {
}

H6Problem::~H6Problem() {
}

const char* H6Problem::name() const{
    return "H6";
}
const char* H6Problem::description() const{
    return NULL;
}
Codification* H6Problem::NewCodification() throw(exception){
    return new H6Codification();
}
Objective* H6Problem::NewObjective() throw(exception){
    return new H6Objective();
}
void H6Problem::services(LinkerNodes *com) throw(exception){
    com->addf(&H6Operator::obj);
}
