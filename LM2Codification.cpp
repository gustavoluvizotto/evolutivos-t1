/* 
 * File:   LM2Codification.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "LM2Codification.h"

LM2Codification::LM2Codification() {
    cromo = new double[10];
}
LM2Codification::~LM2Codification() {
    delete cromo;
}
void LM2Codification::Copy(Problem *prob, Codification *source) throw(exception){
    LM2Codification* codif = dynamic_cast<LM2Codification*>(source);
    
    for(int i=0; i<10; i++){
        this->cromo[i] = codif->cromo[i];
    }
}
Codification* LM2Codification::New(Problem *prob) throw(exception){
    return new LM2Codification();
}

