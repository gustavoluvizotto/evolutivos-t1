/* 
 * File:   cReal.cpp
 * Author: marcio
 * 
 * Created on 11 de Junho de 2013, 17:44
 */

#include "cReal.h"

#include "uUtil.h"
#include "LinkerParameters.h"
#include "Problem.h"

#include <cstddef>
#include <cmath>
#include <cstring>

cReal::cReal(int size) : length(size){
    x = new double[size];
}
cReal::~cReal(){
    delete[] x;
}
void cReal::Copy(Problem *prob, Codification *source) throw(exception){
    cReal* codif = dynamic_cast<cReal*>(source);
    memcpy(this->x, codif->x, length*sizeof(double));
}
Codification* cReal::New(Problem *prob) throw(exception){
    return new cReal(length);
}
double cReal::X(int i){
    return x[i];
}
double cReal::X(int i, double a, double b){
    return a + x[i]*(b-a);
}



//------------------- default operators ------------------
void cReal::INIT::initialize(Problem* prob, Codification* B) throw (exception) {
    cReal* ind = dynamic_cast<cReal*> (B);
    for (int i = 0; i < ind->length; i++) {
        ind->x[i] = prob->rmd->nextDouble();
    }
}

Codification* cReal::CrossAvg::crossover(Problem* prob, Codification* A, Codification* B) throw (exception) {
    cReal* ind1 = dynamic_cast<cReal*> (A);
    cReal* ind2 = dynamic_cast<cReal*> (B);
    cReal* child = dynamic_cast<cReal*> (ind1->New(prob));
    for (int i = 0; i < child->length; i++) {
        child->x[i] = (ind1->x[i] + ind2->x[i]) / 2.0;
    }
    return child;
}
Codification* cReal::CrossGeo::crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception) {
    cReal* ind1 = dynamic_cast<cReal*> (A1);
    cReal* ind2 = dynamic_cast<cReal*> (A2);
    cReal* child = dynamic_cast<cReal*> (ind1->New(prob));
    for (int i = 0; i < child->length; i++) {
        child->x[i] = sqrt(ind1->x[i] * ind2->x[i]);
    }
    return child;
}
Codification* cReal::CrossOnePoint::crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception) {
    cReal* ind1 = dynamic_cast<cReal*> (A1);
    cReal* ind2 = dynamic_cast<cReal*> (A2);
    cReal* child = dynamic_cast<cReal*> (ind1->New(prob));
    int tc = prob->rmd->nextInt(child->length);
    memcpy(child->x, ind1->x, tc * sizeof (double)); //[0..tc-1]
    memcpy(&(child->x[tc]), &(ind2->x[tc]), (child->length - tc) * sizeof (double)); //[tc..size]
    return child;
}
Codification* cReal::CrossTwoPoint::crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception) {
    cReal* ind1 = dynamic_cast<cReal*> (A1);
    cReal* ind2 = dynamic_cast<cReal*> (A2);
    cReal* child = dynamic_cast<cReal*> (ind1->New(prob));

    prob->rmd->nextCutPoints(points, 2, child->length);

    bool flag = true;
    int j = 0;
    for (int i = 0; i < 2; i++) {
        int p = points[i];
        if (flag) {
            uUtil::arraycopy(ind1->x, j, child->x, j, p - j);
        } else {
            uUtil::arraycopy(ind2->x, j, child->x, j, p - j);
        }
        j = p;
        flag = !flag;
    }
    if (flag) {
        uUtil::arraycopy(ind1->x, j, child->x, j, child->length - j);
    } else {
        uUtil::arraycopy(ind2->x, j, child->x, j, child->length - j);
    }
    delete[] points;
    return child;
}
Codification* cReal::CrossOX::crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception) {
    cReal* ind1 = dynamic_cast<cReal*> (A1);
    cReal* ind2 = dynamic_cast<cReal*> (A2);
    cReal* child = dynamic_cast<cReal*> (ind1->New(prob));
    for (int i = 0; i < child->length; i++) {
        child->x[i] = prob->rmd->nextBoolean() ? ind1->x[i] : ind2->x[i];
    }
    return child;
}
Codification* cReal::CrossOXFast::crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception) {
    cReal* ind1 = dynamic_cast<cReal*> (A1);
    cReal* ind2 = dynamic_cast<cReal*> (A2);
    cReal* child = dynamic_cast<cReal*> (ind1->New(prob));
    mask = prob->rmd->nextMask(mask, child->length);
    for (int i = 0; i < child->length; i++) {
        child->x[i] = uUtil::decode(mask, i, ind1->x[i], ind2->x[i]);
    }
    return child;
}
void cReal::CrossBLX::parameters(LinkerParameters* win) throw (exception) {
    alpha = win->Dbl("BLX-alpha", 1.0, 0.0, 2.0);
}
Codification* cReal::CrossBLX::crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception) {
    cReal* ind1 = dynamic_cast<cReal*> (A1);
    cReal* ind2 = dynamic_cast<cReal*> (A2);
    cReal* child = dynamic_cast<cReal*> (ind1->New(prob));
    for (int i = 0; i < child->length; i++) {
        //beta pertence a uma distribuição uniforme de (-Alfa, Alfa+1)
        double beta = -alpha + (1 + alpha) * prob->rmd->nextDouble();
        //c = p1 + beta*(p2 - p1 )
        child->x[i] = ind1->x[i] + beta * (ind2->x[i] - ind1->x[i]);
        child->x[i] = uUtil::bound(child->x[i], 0.0, 1.0);
    }
    return child;
}
Codification* cReal::CrossHeur::crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception) {
    cReal* ind1 = dynamic_cast<cReal*> (A1);
    cReal* ind2 = dynamic_cast<cReal*> (A2);
    cReal* child = dynamic_cast<cReal*> (ind1->New(prob));
    for (int i = 0; i < child->length; i++) {
        double r = prob->rmd->nextDouble();
        child->x[i] = ind1->x[i] + r * (ind1->x[i] - ind2->x[i]);
        child->x[i] = uUtil::bound(child->x[i], 0.0, 1.0);
    }
    return child;
    }
Codification* cReal::CrossLinear::crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception) {
    cReal* ind1 = dynamic_cast<cReal*> (A1);
    cReal* ind2 = dynamic_cast<cReal*> (A2);
    cReal* child = dynamic_cast<cReal*> (ind1->New(prob));
    int type = prob->rmd->nextInt(3);
    switch (type) {
        case 0:
            for (int i = 0; i < child->length; i++) {
                child->x[i] = (ind1->x[i] + ind2->x[i]) / 2;
            }
            break;
        case 1:
            for (int i = 0; i < child->length; i++) {
                child->x[i] = 1.5 * ind1->x[i] - 0.5 * ind2->x[i];
                child->x[i] = uUtil::bound(child->x[i], 0.0, 1.0);
            }
            break;
        default:
            for (int i = 0; i < child->length; i++) {
                child->x[i] = -0.5 * ind1->x[i] + 1.5 * ind2->x[i];
                child->x[i] = uUtil::bound(child->x[i], 0.0, 1.0);
            }
            break;
    }
    return child;
}
Codification* cReal::CrossAritm::crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception) {
    cReal* ind1 = dynamic_cast<cReal*> (A1);
    cReal* ind2 = dynamic_cast<cReal*> (A2);
    cReal* child = dynamic_cast<cReal*> (ind1->New(prob));
    for (int i = 0; i < child->length; i++) {
        double r = prob->rmd->nextDouble();
        child->x[i] = r * ind1->x[i] + (1 - r) * ind2->x[i];
        child->x[i] = uUtil::bound(child->x[i], 0.0, 1.0);
    }
    return child;
}


void cReal::MutReplace::mutation(Problem* prob, Codification* A) throw (exception) {
    cReal* ind = dynamic_cast<cReal*> (A);
    int i = prob->rmd->nextInt(ind->length);
    ind->x[i] = prob->rmd->nextDouble();
}
void cReal::MutLimit::mutation(Problem* prob, Codification* A) throw (exception) {
    cReal* ind = dynamic_cast<cReal*> (A);
    int i = prob->rmd->nextInt(ind->length);
    ind->x[i] = prob->rmd->nextBoolean() ? 0 : 1;
}
void cReal::MutInvert::mutation(Problem* prob, Codification* A) throw (exception) {
    cReal* ind = dynamic_cast<cReal*> (A);
    int i = prob->rmd->nextInt(ind->length);
    ind->x[i] = 1 - ind->x[i];
}



void cReal::MovReplace::local_search(Problem* prob, Codification* A) throw (exception) {
    cReal* ind = dynamic_cast<cReal*> (A);
    int i = prob->rmd->nextInt(ind->length);
    ind->x[i] = prob->rmd->nextDouble();
}
void cReal::MovLimit::local_search(Problem* prob, Codification* A) throw (exception) {
    cReal* ind = dynamic_cast<cReal*> (A);
    int i = prob->rmd->nextInt(ind->length);
    ind->x[i] = prob->rmd->nextBoolean() ? 0 : 1;
}
void cReal::MovInvert::local_search(Problem* prob, Codification* A) throw (exception) {
    cReal* ind = dynamic_cast<cReal*> (A);
    int i = prob->rmd->nextInt(ind->length);
    ind->x[i] = 1 - ind->x[i];
}


