/* 
 * File:   pCodification.cpp
 * Author: andre
 * 
 * Created on 22 de Janeiro de 2013, 16:15
 */

#include "Codification.h"

#include "Problem.h"
#include "StreamPrinter.h"
#include "LinkerResults.h"

Codification::Codification() {
}


Codification::~Codification() {
}
void Codification::printer(Problem *prob, StreamPrinter *link) throw(exception){
    
}
void Codification::resulter(Problem *prob, LinkerResults *link) throw(exception) {
    
}
Codification *Codification::Clone(Problem *prob) throw(exception){
    Codification *sol = New(prob);
    sol->Copy(prob,this);
    return sol;
}


