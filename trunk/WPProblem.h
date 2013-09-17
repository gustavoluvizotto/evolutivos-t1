/* 
 * File:   WPProblem.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef WPPROBLEM_H
#define	WPPROBLEM_H

#include "Problem.h"

class WPProblem : public Problem {
public:
    WPProblem();
    virtual ~WPProblem();

    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw (exception);
    virtual Objective *NewObjective() throw (exception);
    virtual void services(LinkerNodes *com) throw (exception);
private:

};

#endif	/* WPPROBLEM_H */
