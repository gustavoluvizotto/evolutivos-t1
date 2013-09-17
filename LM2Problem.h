/* 
 * File:   LM2Problem.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef LM2PROBLEM_H
#define	LM2PROBLEM_H

#include "Problem.h"

class LM2Problem : public Problem{
public:
    LM2Problem();
    virtual ~LM2Problem();
    
    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw(exception);
    virtual Objective *NewObjective() throw(exception);
    virtual void services(LinkerNodes *com) throw(exception);
private:

};

#endif	/* LM2PROBLEM_H */

