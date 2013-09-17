/* 
 * File:   EXPProblem.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef EXPPROBLEM_H
#define	EXPPROBLEM_H

#include "Problem.h"

class EXPProblem : public Problem{
public:
    EXPProblem();
    virtual ~EXPProblem();
    
    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw(exception);
    virtual Objective *NewObjective() throw(exception);
    virtual void services(LinkerNodes *com) throw(exception);
private:

};

#endif	/* EXPPROBLEM_H */

