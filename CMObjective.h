/* 
 * File:   CMObjective.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef CMOBJECTIVE_H
#define	CMOBJECTIVE_H

#include "SingleObjective.h"


class CMObjective: public SingleObjective {
public:
    CMObjective();
    virtual ~CMObjective();
    
    virtual void Evaluate(Problem* mem, Codification* codif) throw(exception);
    virtual Objective* New(Problem* mem) throw(exception);
    
private:

};

#endif	/* CMOBJECTIVE_H */

