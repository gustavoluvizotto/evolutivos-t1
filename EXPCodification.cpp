/* 
 * File:   EXPCodification.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "EXPCodification.h"

EXPCodification::EXPCodification() {
    cromo = new double[10];	// n = 10
}

EXPCodification::~EXPCodification() {
    delete cromo;
}

void EXPCodification::Copy(Problem *prob, Codification *source) throw (exception) {
    EXPCodification* codif = dynamic_cast<EXPCodification*> (source);
    for (int i = 0; i < 10; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* EXPCodification::New(Problem *prob) throw (exception) {
    return new EXPCodification();
}

