/* 
 * File:   HVCodification.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "HVCodification.h"

HVCodification::HVCodification() {
    cromo = new double[3];
}

HVCodification::~HVCodification() {
    delete cromo;
}

void HVCodification::Copy(Problem *prob, Codification *source) throw (exception) {
    HVCodification* codif = dynamic_cast<HVCodification*> (source);

    for (int i = 0; i < 3; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* HVCodification::New(Problem *prob) throw (exception) {
    return new HVCodification();
}

