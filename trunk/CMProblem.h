/* 
 * File:   CMProblem.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef CMPROBLEM_H
#define	CMPROBLEM_H

#include "Problem.h"

class CMProblem : public Problem{
public:
    CMProblem();
    virtual ~CMProblem();
    
    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw(exception);
    virtual Objective *NewObjective() throw(exception);
    virtual void services(LinkerNodes *com) throw(exception);
private:

};

#endif	/* CMPROBLEM_H */

