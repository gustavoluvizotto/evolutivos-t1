/* 
 * File:   pBest.h
 * Author: andre
 *
 * Created on 14 de Dezembro de 2012, 17:14
 */

#ifndef BEST_H
#define	BEST_H

#include "Node.h"

//forward declaration
class Problem;
class Solution;
class LinkerNodes;
class LinkerParameters;
class LinkerValidations;
class LinkerResults;


class Best: public Node {
public:
    Best();    
    virtual ~Best();
    
    
    virtual void addBetter(Problem *mem, Solution *sol) throw(exception) = 0;
    virtual double time_now() = 0;
    virtual double time_best() = 0;
    virtual double time_after() = 0;
    
    virtual const char* name() const = 0 ;
    virtual const char* description() const = 0;

    virtual void services(LinkerNodes *com) throw(exception) = 0;
    virtual void load() throw(exception) = 0;
    virtual void start() throw(exception) = 0;

    virtual void parameters(LinkerParameters *com) throw(exception) {}
    virtual bool validation(LinkerValidations *com) throw(exception) {return true;}
    virtual void results(LinkerResults *com) throw(exception) {}
private:

};

#endif	/* PBEST_H */

