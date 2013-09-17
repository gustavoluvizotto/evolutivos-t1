/* 
 * File:   GRPObjective.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef GRPOBJECTIVE_H
#define	GRPOBJECTIVE_H

#include "SingleObjective.h"


class GRPObjective: public SingleObjective {
public:
    GRPObjective();
    virtual ~GRPObjective();
    
    virtual void Evaluate(Problem* mem, Codification* codif) throw(exception);
    virtual Objective* New(Problem* mem) throw(exception);
    
private:

};

#endif	/* GRPOBJECTIVE_H */

