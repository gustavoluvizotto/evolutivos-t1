/* 
 * File:   WPObjective.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef WPOBJECTIVE_H
#define	WPOBJECTIVE_H

#include "SingleObjective.h"

class WPObjective : public SingleObjective {
public:
    WPObjective();
    virtual ~WPObjective();

    virtual void Evaluate(Problem* mem, Codification* codif) throw (exception);
    virtual Objective* New(Problem* mem) throw (exception);

private:

};

#endif	/* WPOBJECTIVE_H */
