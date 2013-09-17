/* 
 * File:   ACKCodification.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "ACKCodification.h"

ACKCodification::ACKCodification() {
    cromo = new double[10];
}

ACKCodification::~ACKCodification() {
    delete cromo;
}

void ACKCodification::Copy(Problem *prob, Codification *source) throw (exception) {
    ACKCodification* codif = dynamic_cast<ACKCodification*> (source);
    for (int i = 0; i < 10; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* ACKCodification::New(Problem *prob) throw (exception) {
    return new ACKCodification();
}
