/* 
 * File:   H6Problem.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:10
 */

#ifndef H6PROBLEM_H
#define	H6PROBLEM_H

#include "Problem.h"

class H6Problem : public Problem{
public:
    H6Problem();
    virtual ~H6Problem();
    
    virtual const char* name() const;
    virtual const char* description() const;
    virtual Codification *NewCodification() throw(exception);
    virtual Objective *NewObjective() throw(exception);
    virtual void services(LinkerNodes *com) throw(exception);
private:

};

#endif	/* H6PROBLEM_H */

