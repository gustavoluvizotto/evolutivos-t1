/* 
 * File:   pRealSingleObjProblem.cpp
 * Author: marcio
 * 
 * Created on 18 de Junho de 2013, 16:05
 */

#include "pRealSingleObjProblem.h"
#include "fRealOperator.h"
#include "Best.h"
#include "Instance.h"
#include "NodeFactory.h"
#include "Node.h"
#include "BestSol.h"
#include "aRealSingleObj.h"
#include "cReal.h"
#include "SingleObjective.h"
#include <stddef.h>

class pRealSingleObjProblem::SingleObj : public SingleObjective{
public:
    virtual void Evaluate(Problem* A, Codification* B) throw(exception){
        pRealSingleObjProblem* prob = dynamic_cast<pRealSingleObjProblem*> (A);
        cReal* codif = dynamic_cast<cReal*> (B);
        set(prob->function->F(codif->x, codif->length));
    }
    virtual Objective* New(Problem* prob) throw(exception){
        return new pRealSingleObjProblem::SingleObj();
    }
};


pRealSingleObjProblem::pRealSingleObjProblem(aRealSingleObj* f): function(f){
}
pRealSingleObjProblem::~pRealSingleObjProblem() {
}

const char* pRealSingleObjProblem::name() const{
    return function->name();
}
const char* pRealSingleObjProblem::description() const{
    return NULL;
}
Codification* pRealSingleObjProblem::NewCodification() throw(exception){
    return new cReal(function->size());
}
Objective* pRealSingleObjProblem::NewObjective() throw(exception){
    return new pRealSingleObjProblem::SingleObj();
}
Best* pRealSingleObjProblem::NewBest(){
    return &BestSol::obj;
}
Node* pRealSingleObjProblem::NewParameter() {
    return NULL;
}
Instance* pRealSingleObjProblem::NewInstance() {
    return NULL;
}
const Factory* pRealSingleObjProblem::NewOperators() {
    return &fRealOperator::obj;
}

