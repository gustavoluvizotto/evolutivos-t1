/* 
 * File:   FUNCodification.cpp
 * Author: marcio
 * 
 * Created on 29 de Agosto de 2013, 16:57
 */

#include "FUNCodification.h"
#include "FUNProblem.h"

#include <string.h>
#include <cstdio>

FUNCodification::FUNCodification(Problem* prob) {
    
}
FUNCodification::~FUNCodification() {

}
void FUNCodification::Copy(Problem *prob, Codification *source) throw(exception){
    FUNCodification* codif = dynamic_cast<FUNCodification*>(source);
    this->x = codif->x;
}
Codification* FUNCodification::New(Problem *prob) throw(exception){
    return new FUNCodification(prob);
}

