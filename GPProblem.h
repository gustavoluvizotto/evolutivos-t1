/* 
 * File:   GPProblem.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef GPPROBLEM_H
#define	GPPROBLEM_H

#include "Problem.h"

class GPProblem : public Problem{
public:
    GPProblem();
    virtual ~GPProblem();
    
    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw(exception);
    virtual Objective *NewObjective() throw(exception);
    virtual void services(LinkerNodes *com) throw(exception);
private:

};

#endif	/* GPPROBLEM_H */

