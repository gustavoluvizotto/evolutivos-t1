/* 
 * File:   SINObjective.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef SINOBJECTIVE_H
#define	SINOBJECTIVE_H

#include "SingleObjective.h"


class SINObjective: public SingleObjective {
public:
    SINObjective();
    virtual ~SINObjective();
    
    virtual void Evaluate(Problem* mem, Codification* codif) throw(exception);
    virtual Objective* New(Problem* mem) throw(exception);
    
private:
    double decode(int *cromo, int tam, double min, double max);
};

#endif	/* SINOBJECTIVE_H */
