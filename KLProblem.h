/* 
 * File:   KLProblem.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef KLPROBLEM_H
#define	KLPROBLEM_H

#include "Problem.h"

class KLProblem : public Problem {
public:
    KLProblem();
    virtual ~KLProblem();

    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw (exception);
    virtual Objective *NewObjective() throw (exception);
    virtual void services(LinkerNodes *com) throw (exception);
private:

};

#endif	/* KLPROBLEM_H */

