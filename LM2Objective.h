/* 
 * File:   LM2Objective.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef LM2OBJECTIVE_H
#define	LM2OBJECTIVE_H

#include "SingleObjective.h"


class LM2Objective: public SingleObjective {
public:
    LM2Objective();
    virtual ~LM2Objective();
    
    virtual void Evaluate(Problem* mem, Codification* codif) throw(exception);
    virtual Objective* New(Problem* mem) throw(exception);
    
private:

};

#endif	/* LM2OBJECTIVE_H */

