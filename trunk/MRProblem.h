/* 
 * File:   MRProblem.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef MRPROBLEM_H
#define	MRPROBLEM_H

#include "Problem.h"

class MRProblem : public Problem {
public:
    MRProblem();
    virtual ~MRProblem();

    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw (exception);
    virtual Objective *NewObjective() throw (exception);
    virtual void services(LinkerNodes *com) throw (exception);
private:

};

#endif	/* MRPROBLEM_H */
