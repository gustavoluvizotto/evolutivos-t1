/* 
 * File:   MCPCodification.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "MCPCodification.h"

MCPCodification::MCPCodification() {
    cromo = new double[4];
}

MCPCodification::~MCPCodification() {
    delete cromo;
}

void MCPCodification::Copy(Problem *prob, Codification *source) throw (exception) {
    MCPCodification* codif = dynamic_cast<MCPCodification*> (source);
    
    for (int i = 0; i < 4; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* MCPCodification::New(Problem *prob) throw (exception) {
    return new MCPCodification();
}

