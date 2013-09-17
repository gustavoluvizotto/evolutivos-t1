/* 
 * File:   CMCodification.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "CMCodification.h"

CMCodification::CMCodification() {
    cromo = new double[4];
}

CMCodification::~CMCodification() {
    delete cromo;
}

void CMCodification::Copy(Problem *prob, Codification *source) throw (exception) {
    CMCodification* codif = dynamic_cast<CMCodification*> (source);
    for (int i = 0; i < 4; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* CMCodification::New(Problem *prob) throw (exception) {
    return new CMCodification();
}

