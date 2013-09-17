/* 
 * File:   MRCodification.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "MRCodification.h"

MRCodification::MRCodification() {
    cromo = new double[3];
}

MRCodification::~MRCodification() {
    delete cromo;
}

void MRCodification::Copy(Problem *prob, Codification *source) throw (exception) {
    MRCodification* codif = dynamic_cast<MRCodification*> (source);
    for (int i = 0; i < 3; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* MRCodification::New(Problem *prob) throw (exception) {
    return new MRCodification();
}
