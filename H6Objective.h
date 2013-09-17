/* 
 * File:   H6Objective.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:24
 */

#ifndef H6OBJECTIVE_H
#define	H6OBJECTIVE_H

#include "SingleObjective.h"


class H6Objective: public SingleObjective {
public:
    H6Objective();
    virtual ~H6Objective();
    
    virtual void Evaluate(Problem* mem, Codification* codif) throw(exception);
    virtual Objective* New(Problem* mem) throw(exception);
    
private:

};

#endif	/* H6OBJECTIVE_H */

