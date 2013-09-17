/* 
 * File:   EXPObjective.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef EXPOBJECTIVE_H
#define	EXPOBJECTIVE_H

#include "SingleObjective.h"


class EXPObjective: public SingleObjective {
public:
    EXPObjective();
    virtual ~EXPObjective();
    
    virtual void Evaluate(Problem* mem, Codification* codif) throw(exception);
    virtual Objective* New(Problem* mem) throw(exception);
    
private:

};

#endif	/* EXPOBJECTIVE_H */

