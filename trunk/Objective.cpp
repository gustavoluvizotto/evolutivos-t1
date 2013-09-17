/* 
 * File:   pObjective.cpp
 * Author: andre
 * 
 * Created on 22 de Janeiro de 2013, 16:14
 */

#include "Objective.h"

Objective::Objective() {
}

Objective::~Objective() {
}

    
Objective* Objective::Clone(Problem* mem) throw(exception){
    Objective* obj = New(mem);
    obj->Copy(mem, this);
    return obj;
}

bool Objective::penalized() throw(exception){
    return false;
}

