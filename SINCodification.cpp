/* 
 * File:   SINCodification.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "SINCodification.h"

SINCodification::SINCodification() {
    cromo = new int[10];
}

SINCodification::~SINCodification() {
    delete cromo;
}

void SINCodification::Copy(Problem *prob, Codification *source) throw (exception) {
    SINCodification* codif = dynamic_cast<SINCodification*> (source);
    for (int i = 0; i < 10; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* SINCodification::New(Problem *prob) throw (exception) {
    return new SINCodification();
}
