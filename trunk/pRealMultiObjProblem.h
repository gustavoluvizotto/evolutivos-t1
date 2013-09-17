/* 
 * File:   pRealMultiObjProblem.h
 * Author: marcio
 *
 * Created on 18 de Junho de 2013, 16:29
 */

#ifndef PREALMULTIOBJPROBLEM_H
#define	PREALMULTIOBJPROBLEM_H

#include "MultiProblem.h"

class aRealMultiObj;

class pRealMultiObjProblem : public MultiProblem {
public:
    pRealMultiObjProblem(aRealMultiObj* function);
    virtual ~pRealMultiObjProblem();
    virtual void construct() throw(exception);
    virtual int goals() const;
    virtual const char* name() const;
    virtual const char* description() const;   
    virtual Objective *NewObjective() throw(exception);
    virtual Codification *NewCodification() throw(exception);
protected:
    virtual Best *NewBest();
    virtual Node *NewParameter();
    virtual Instance *NewInstance();
    virtual const Factory *NewOperators();
private:
    aRealMultiObj* function;
    
    class MultiObj;
};

#endif	/* PREALMULTIOBJPROBLEM_H */

