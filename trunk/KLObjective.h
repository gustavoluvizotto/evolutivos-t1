/* 
 * File:   KLObjective.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef KLOBJECTIVE_H
#define	KLOBJECTIVE_H

#include "SingleObjective.h"

class KLObjective : public SingleObjective {
public:
    KLObjective();
    virtual ~KLObjective();

    virtual void Evaluate(Problem* mem, Codification* codif) throw (exception);
    virtual Objective* New(Problem* mem) throw (exception);

private:

};

#endif	/* KLOBJECTIVE_H */

