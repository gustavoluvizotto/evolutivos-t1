/* 
 * File:   SINU20Codification.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "SINU20Codification.h"

SINU20Codification::SINU20Codification() {
    cromo = new double[20];
}

SINU20Codification::~SINU20Codification() {
    delete cromo;
}

void SINU20Codification::Copy(Problem *prob, Codification *source) throw (exception) {
    SINU20Codification* codif = dynamic_cast<SINU20Codification*> (source);
    for (int i = 0; i < 20; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* SINU20Codification::New(Problem *prob) throw (exception) {
    return new SINU20Codification();
}
