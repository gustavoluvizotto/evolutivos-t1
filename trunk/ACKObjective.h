/* 
 * File:   ACKObjective.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef ACKOBJECTIVE_H
#define	ACKOBJECTIVE_H

#include "SingleObjective.h"

class ACKObjective : public SingleObjective {
public:
    ACKObjective();
    virtual ~ACKObjective();

    virtual void Evaluate(Problem* mem, Codification* codif) throw (exception);
    virtual Objective* New(Problem* mem) throw (exception);

private:

};

#endif	/* ACKOBJECTIVE_H */
