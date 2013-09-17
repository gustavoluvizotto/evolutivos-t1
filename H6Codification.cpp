/* 
 * File:   H6Codification.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:18
 */

#include "H6Codification.h"

H6Codification::H6Codification() {
    cromo = new double[6];	// j = 6
}

H6Codification::~H6Codification() {
    delete cromo;
}

void H6Codification::Copy(Problem *prob, Codification *source) throw (exception) {
    H6Codification* codif = dynamic_cast<H6Codification*> (source);
    for (int i = 0; i < 6; i++) {
        this->cromo[i] = codif->cromo[i];
    }
}

Codification* H6Codification::New(Problem *prob) throw (exception) {
    return new H6Codification();
}

