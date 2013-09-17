/* 
 * File:   HSKProblem.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef HSKPROBLEM_H
#define	HSKPROBLEM_H

#include "Problem.h"

class HSKProblem : public Problem{
public:
    HSKProblem();
    virtual ~HSKProblem();
    
    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw(exception);
    virtual Objective *NewObjective() throw(exception);
    virtual void services(LinkerNodes *com) throw(exception);
private:

};

#endif	/* HSKPROBLEM_H */

