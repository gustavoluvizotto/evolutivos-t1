/* 
 * File:   SINU20Objective.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef SINU20OBJECTIVE_H
#define	SINU20OBJECTIVE_H

#include "SingleObjective.h"

class SINU20Objective : public SingleObjective {
public:
    SINU20Objective();
    virtual ~SINU20Objective();

    virtual void Evaluate(Problem* mem, Codification* codif) throw (exception);
    virtual Objective* New(Problem* mem) throw (exception);

private:

};

#endif	/* SINU20OBJECTIVE_H */
