/* 
 * File:   fRealOperator.cpp
 * Author: marcio
 * 
 * Created on 11 de Junho de 2013, 18:27
 */

#include "fRealOperator.h"

#include "cReal.h"

const fRealOperator fRealOperator::obj;

fRealOperator::fRealOperator() {
}

fRealOperator::~fRealOperator() {
}

const char* fRealOperator::name()const {
    return "Real-Operators";
}


Node* fRealOperator::NewService(int index)const {
    switch (index) {
        case 0: return new cReal::INIT();
        case 1: return new cReal::CrossAvg();
        case 2: return new cReal::CrossGeo();
        case 3: return new cReal::CrossOnePoint();
        case 4: return new cReal::CrossTwoPoint();
        case 5: return new cReal::CrossOX();
        case 6: return new cReal::CrossOXFast();
        case 7: return new cReal::CrossBLX();
        case 8: return new cReal::CrossHeur();
        case 9: return new cReal::CrossLinear();
        case 10: return new cReal::CrossAritm();
        case 11: return new cReal::MutReplace();
        case 12: return new cReal::MutLimit();
        case 13: return new cReal::MutInvert();
        case 14: return new cReal::MovReplace();
        case 15: return new cReal::MovLimit();
        case 16: return new cReal::MovInvert();
    }
    return NULL;
}

