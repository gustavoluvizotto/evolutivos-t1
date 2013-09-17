/* 
 * File:   pRealSingleObjProblem.h
 * Author: marcio
 *
 * Created on 18 de Junho de 2013, 16:05
 */

#ifndef PREALSINGLEOBJPROBLEM_H
#define	PREALSINGLEOBJPROBLEM_H

#include "Problem.h"

class aRealSingleObj;

class pRealSingleObjProblem : public Problem{
public:
    pRealSingleObjProblem(aRealSingleObj* function);
    virtual ~pRealSingleObjProblem();
    
    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw(exception);
    virtual Objective *NewObjective() throw(exception);
protected:
    virtual Best *NewBest();
    virtual Node *NewParameter();
    virtual Instance *NewInstance();
    virtual const Factory *NewOperators();
private:
    const aRealSingleObj* function;
    
    class SingleObj;
};

#endif	/* PREALSINGLEOBJPROBLEM_H */

