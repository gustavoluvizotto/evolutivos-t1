/* 
 * File:   HVObjective.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef HVOBJECTIVE_H
#define	HVOBJECTIVE_H

#include "SingleObjective.h"


class HVObjective: public SingleObjective {
public:
    HVObjective();
    virtual ~HVObjective();
    
    virtual void Evaluate(Problem* mem, Codification* codif) throw(exception);
    virtual Objective* New(Problem* mem) throw(exception);
    
private:

};

#endif	/* HVOBJECTIVE_H */

