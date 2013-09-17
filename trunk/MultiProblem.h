/* 
 * File:   pMultiProblem.h
 * Author: marcio
 *
 * Created on 11 de Junho de 2013, 15:56
 */

#ifndef MULTIPROBLEM_H
#define	MULTIPROBLEM_H

#include "MultiObjective.h"
#include "Solution.h"
#include "Problem.h"


class MultiProblem : public Problem{
public:
    MultiProblem();
    virtual ~MultiProblem();
    
    double goal(int i, MultiObjective* obj);
    double goal(int i, Solution* sol);
    int compareTo(int i, Solution* a, Solution* b);
    
    virtual int goals() const = 0;
    virtual const char* name() const = 0 ;
    virtual const char* description() const = 0;
    
    virtual Objective *NewObjective() throw(exception) = 0;
    virtual Codification *NewCodification() throw(exception) = 0;
    
protected:
    virtual Best *NewBest() = 0;
};

#endif	/* PMULTIPROBLEM_H */

