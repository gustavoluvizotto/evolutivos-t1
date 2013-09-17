/* 
 * File:   pBestPareto.h
 * Author: andre
 *
 * Created on 22 de Janeiro de 2013, 13:26
 */

#ifndef BESTPARETO_H
#define	BESTPARETO_H

#include "Best.h"


class BestPareto: public Best{
public:
    BestPareto();
    virtual ~BestPareto();
    virtual const char* name() const {}
    virtual const char* description() const {}

    virtual void services(LinkerNodes *com) throw(exception) {}
    virtual void load() throw(exception) {}
    virtual void start() throw(exception){}   

    virtual void addBetter(Problem *mem, Solution *sol) throw(exception) = 0;
    virtual double time_now() {}
    virtual double time_best() {}        
    virtual double time_after() {}
    virtual void results(Problem *mem, LinkerResults *com) throw(exception) = 0;

private:

};

#endif	/* PBESTPARETO_H */

