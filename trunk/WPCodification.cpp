/* 
 * File:   WPCodification.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "WPCodification.h"

WPCodification::WPCodification() {
    cromo = new double[4];
}

WPCodification::~WPCodification() {
    delete cromo;
}

void WPCodification::Copy(Problem *prob, Codification *source) throw (exception) {
    WPCodification* codif = dynamic_cast<WPCodification*> (source);
    for (int i = 0; i < 4; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* WPCodification::New(Problem *prob) throw (exception) {
    return new WPCodification();
}
