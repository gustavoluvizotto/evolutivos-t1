/* 
 * File:   BRProblem.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef BRPROBLEM_H
#define	BRPROBLEM_H

#include "Problem.h"

class BRProblem : public Problem {
public:
    BRProblem();
    virtual ~BRProblem();

    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw (exception);
    virtual Objective *NewObjective() throw (exception);
    virtual void services(LinkerNodes *com) throw (exception);
private:

};

#endif	/* BRPROBLEM_H */
