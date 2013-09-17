/* 
 * File:   MCPProblem.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef MCPPROBLEM_H
#define	MCPPROBLEM_H

#include "Problem.h"

class MCPProblem : public Problem {
public:
    MCPProblem();
    virtual ~MCPProblem();

    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw (exception);
    virtual Objective *NewObjective() throw (exception);
    virtual void services(LinkerNodes *com) throw (exception);
private:

};

#endif	/* MCPPROBLEM_H */

