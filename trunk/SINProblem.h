/* 
 * File:   SINProblem.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef SINPROBLEM_H
#define	SINPROBLEM_H

#include "Problem.h"

class SINProblem : public Problem {
public:
    SINProblem();
    virtual ~SINProblem();

    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw (exception);
    virtual Objective *NewObjective() throw (exception);
    virtual void services(LinkerNodes *com) throw (exception);
private:

};

#endif	/* SINPROBLEM_H */
