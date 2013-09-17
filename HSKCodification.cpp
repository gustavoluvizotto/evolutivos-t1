/* 
 * File:   HSKCodification.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "HSKCodification.h"

HSKCodification::HSKCodification() {
    cromo = new double[2];
}
HSKCodification::~HSKCodification() {
    delete cromo;
}
void HSKCodification::Copy(Problem *prob, Codification *source) throw(exception){
    HSKCodification* codif = dynamic_cast<HSKCodification*>(source);
    
    for(int i=0; i<2; i++){
        this->cromo[i] = codif->cromo[i];
    }
}
Codification* HSKCodification::New(Problem *prob) throw(exception){
    return new HSKCodification();
}

