/* 
 * File:   BRObjective.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef BROBJECTIVE_H
#define	BROBJECTIVE_H

#include "SingleObjective.h"

class BRObjective : public SingleObjective {
public:
    BRObjective();
    virtual ~BRObjective();

    virtual void Evaluate(Problem* mem, Codification* codif) throw (exception);
    virtual Objective* New(Problem* mem) throw (exception);

private:

};

#endif	/* BROBJECTIVE_H */
