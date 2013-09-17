/* 
 * File:   FUNProblem.h
 * Author: marcio
 *
 * Created on 29 de Agosto de 2013, 16:53
 */

#ifndef FUNPROBLEM_H
#define	FUNPROBLEM_H

#include "Problem.h"

class FUNProblem : public Problem{
public:
    FUNProblem();
    virtual ~FUNProblem();
    
    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw(exception);
    virtual Objective *NewObjective() throw(exception);
    virtual void services(LinkerNodes *com) throw(exception);
private:
    
};
#endif	/* FUNPROBLEM_H */

