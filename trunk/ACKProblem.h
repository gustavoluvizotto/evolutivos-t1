/* 
 * File:   ACKProblem.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef ACKPROBLEM_H
#define	ACKPROBLEM_H

#include "Problem.h"

class ACKProblem : public Problem {
public:
    ACKProblem();
    virtual ~ACKProblem();

    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw (exception);
    virtual Objective *NewObjective() throw (exception);
    virtual void services(LinkerNodes *com) throw (exception);
private:

};

#endif	/* ACKPROBLEM_H */
