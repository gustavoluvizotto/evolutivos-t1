/* 
 * File:   FUNObjective.h
 * Author: marcio
 *
 * Created on 29 de Agosto de 2013, 16:59
 */

#ifndef FUNOBJECTIVE_H
#define	FUNOBJECTIVE_H

#include "Objective.h"
#include "SingleObjective.h"

class FUNObjective : public SingleObjective{
public:
    FUNObjective();
    virtual ~FUNObjective();
    
    virtual void Evaluate(Problem* mem, Codification* codif) throw(exception);
   
    virtual Objective* New(Problem* mem) throw(exception);
    
private:

};

#endif	/* FUNOBJECTIVE_H */

