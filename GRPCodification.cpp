/* 
 * File:   GRPCodification.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "GRPCodification.h"

GRPCodification::GRPCodification() {
    cromo = new double[3];
}

GRPCodification::~GRPCodification() {
    delete cromo;
}

void GRPCodification::Copy(Problem *prob, Codification *source) throw (exception) {
    GRPCodification* codif = dynamic_cast<GRPCodification*> (source);
    for (int i = 0; i < 3; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* GRPCodification::New(Problem *prob) throw (exception) {
    return new GRPCodification();
}

