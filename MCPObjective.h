/* 
 * File:   MCPObjective.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef MCPOBJECTIVE_H
#define	MCPOBJECTIVE_H

#include "SingleObjective.h"

class MCPObjective : public SingleObjective {
public:
    MCPObjective();
    virtual ~MCPObjective();

    virtual void Evaluate(Problem* mem, Codification* codif) throw (exception);
    virtual Objective* New(Problem* mem) throw (exception);

private:

};

#endif	/* MCPOBJECTIVE_H */

