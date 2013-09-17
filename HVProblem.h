/* 
 * File:   HVProblem.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef HVPROBLEM_H
#define	HVPROBLEM_H

#include "Problem.h"

class HVProblem : public Problem{
public:
    HVProblem();
    virtual ~HVProblem();
    
    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw(exception);
    virtual Objective *NewObjective() throw(exception);
    virtual void services(LinkerNodes *com) throw(exception);
private:

};

#endif	/* HVPROBLEM_H */

