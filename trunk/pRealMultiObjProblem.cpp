/* 
 * File:   pRealMultiObjProblem.cpp
 * Author: marcio
 * 
 * Created on 18 de Junho de 2013, 16:29
 */

#include "pRealMultiObjProblem.h"
#include "fRealOperator.h"
#include "aRealMultiObj.h"
#include "cReal.h"

#include <stddef.h>


class pRealMultiObjProblem::MultiObj : public MultiObjective{
public:
    MultiObj(const aRealMultiObj* f) : MultiObjective(f->goals(), f->bounds()){
    }
    virtual void Evaluate(Problem* A, Codification* B) throw(exception){
        pRealMultiObjProblem* prob = dynamic_cast<pRealMultiObjProblem*> (A);
        cReal* codif = dynamic_cast<cReal*> (B);
        for(int i=0; i<prob->function->goals(); i++){
            set(i, prob->function->F(i, codif->x, codif->length));
        }
    }
    virtual Objective* New(Problem* A) throw(exception){
        pRealMultiObjProblem* prob = dynamic_cast<pRealMultiObjProblem*> (A);
        return new pRealMultiObjProblem::MultiObj(prob->function);
    }
};


pRealMultiObjProblem::pRealMultiObjProblem(aRealMultiObj* f) : function(f){
    
}
pRealMultiObjProblem::~pRealMultiObjProblem() {
}
void pRealMultiObjProblem::construct() throw(exception){
    function->construct();
}
int pRealMultiObjProblem::goals() const{
    return function->goals();
}
const char* pRealMultiObjProblem::name() const{
    return function->name();
}
const char* pRealMultiObjProblem::description() const{
    return NULL;
}
Codification* pRealMultiObjProblem::NewCodification() throw(exception){
    return new cReal(function->size());
}
Objective* pRealMultiObjProblem::NewObjective() throw(exception){
    return new pRealMultiObjProblem::MultiObj(function);
}
Best* pRealMultiObjProblem::NewBest(){
    return NULL;
}
Instance* pRealMultiObjProblem::NewInstance() {
    return NULL;
}
Node* pRealMultiObjProblem::NewParameter() {
    return NULL;
}
const Factory* pRealMultiObjProblem::NewOperators() {
    return &fRealOperator::obj;
}

