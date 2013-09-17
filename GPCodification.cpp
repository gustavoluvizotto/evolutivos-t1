/* 
 * File:   GPCodification.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "GPCodification.h"

GPCodification::GPCodification() {
    cromo = new double[2];	// x1 e x2
}

GPCodification::~GPCodification() {
    delete cromo;
}

void GPCodification::Copy(Problem *prob, Codification *source) throw (exception) {
    GPCodification* codif = dynamic_cast<GPCodification*> (source);
    for (int i = 0; i < 2; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* GPCodification::New(Problem *prob) throw (exception) {
    return new GPCodification();
}

