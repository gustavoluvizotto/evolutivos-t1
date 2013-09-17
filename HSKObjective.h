/* 
 * File:   HSKObjective.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef HSKOBJECTIVE_H
#define	HSKOBJECTIVE_H

#include "SingleObjective.h"


class HSKObjective: public SingleObjective {
public:
    HSKObjective();
    virtual ~HSKObjective();
    
    virtual void Evaluate(Problem* mem, Codification* codif) throw(exception);
    virtual Objective* New(Problem* mem) throw(exception);
    
private:

};

#endif	/* HSKOBJECTIVE_H */

