/* 
 * File:   GRPProblem.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef GRPPROBLEM_H
#define	GRPPROBLEM_H

#include "Problem.h"

class GRPProblem : public Problem{
public:
    GRPProblem();
    virtual ~GRPProblem();
    
    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw(exception);
    virtual Objective *NewObjective() throw(exception);
    virtual void services(LinkerNodes *com) throw(exception);
private:

};

#endif	/* GRPPROBLEM_H */

