/* 
 * File:   KLCodification.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "KLCodification.h"

KLCodification::KLCodification() {
    cromo = new double[4];
}

KLCodification::~KLCodification() {
    delete cromo;
}

void KLCodification::Copy(Problem *prob, Codification *source) throw (exception) {
    KLCodification* codif = dynamic_cast<KLCodification*> (source);
    for (int i = 0; i < 4; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* KLCodification::New(Problem *prob) throw (exception) {
    return new KLCodification();
}

