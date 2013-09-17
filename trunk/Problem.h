/* 
 * File:   pMetaProblem.h
 * Author: andre
 *
 * Created on 22 de Janeiro de 2013, 14:04
 */

#ifndef PROBLEM_H
#define	PROBLEM_H

#include "Node.h"
#include "uRandom.h"

//forward declaration
class Factory;
class Best;
class Codification;
class Objective;
class Solution;
class Instance;

class Problem : public Node {
public:
    Problem();
    virtual ~Problem();
    
    uRandom *rmd;
    Best *best;
    
    virtual void construct() throw(exception);
    virtual void services(LinkerNodes *com) throw(exception);
    virtual void parameters(LinkerParameters *com) throw(exception);
    virtual bool validation(LinkerValidations *com) throw(exception);
    virtual void load() throw(exception);
    virtual void start() throw(exception);
    virtual void results(LinkerResults *com) throw(exception);
    
    virtual const char* name() const = 0 ;
    virtual const char* description() const = 0;
    virtual Codification *NewCodification() throw(exception) = 0;
    virtual Objective *NewObjective() throw(exception) = 0;
    
    Solution *NewSolution() throw(exception);
    Solution *NewSolution(Codification *codif) throw(exception);
    void evaluate(Solution* sol) throw(exception);
    
protected:
    virtual Best* NewBest();
};
/*template <class Mem, class Obj, class Codif, class Sol>
class pMetaSolutionB : public pMetaSolution<Mem, Obj, Codif, Sol> {
    public:            
        pMetaSolutionB()throw(exception) : pMetaSolution(NewObjective(), NewCodification()) {}
        pMetaSolutionB(pObjective *obj, pCodification *codif)throw(exception) : pMetaSolution(obj, codif) {}
        pMetaSolutionB New(pMetaProblem *mem) throw(exception){ return new pMetaSolutionB();}
        pMetaSolution New(pMetaProblem *mem, pCodification *codification) throw(exception){
            return new pMetaSolutionB(objective, codification);
        }
};*/
#endif	/* PMETAPROBLEM_H */

