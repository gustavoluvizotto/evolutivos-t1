/* 
 * File:   BRCodification.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "BRCodification.h"

BRCodification::BRCodification() {
    cromo = new double[2];
}

BRCodification::~BRCodification() {
    delete cromo;
}

void BRCodification::Copy(Problem *prob, Codification *source) throw (exception) {
    BRCodification* codif = dynamic_cast<BRCodification*> (source);
    for (int i = 0; i < 2; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* BRCodification::New(Problem *prob) throw (exception) {
    return new BRCodification();
}
