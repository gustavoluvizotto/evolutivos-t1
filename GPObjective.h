/* 
 * File:   GPObjective.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef GPOBJECTIVE_H
#define	GPOBJECTIVE_H

#include "SingleObjective.h"


class GPObjective: public SingleObjective {
public:
    GPObjective();
    virtual ~GPObjective();
    
    virtual void Evaluate(Problem* mem, Codification* codif) throw(exception);
    virtual Objective* New(Problem* mem) throw(exception);
    
private:

};

#endif	/* GPOBJECTIVE_H */

