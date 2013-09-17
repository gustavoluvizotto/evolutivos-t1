/* 
 * File:   MRObjective.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef MROBJECTIVE_H
#define	MROBJECTIVE_H

#include "SingleObjective.h"

class MRObjective : public SingleObjective {
public:
    MRObjective();
    virtual ~MRObjective();

    virtual void Evaluate(Problem* mem, Codification* codif) throw (exception);
    virtual Objective* New(Problem* mem) throw (exception);

private:

};

#endif	/* MROBJECTIVE_H */
