/* 
 * File:   pBestSol.h
 * Author: andre
 *
 * Created on 22 de Janeiro de 2013, 14:21
 */

#ifndef BESTSOL_H
#define	BESTSOL_H

#include "Best.h"
class nEvaluations;
class aStop;
class StreamPrinter;
class LinkerResults;
class Solution;
class Objective;
class Problem;

class BestSol: public Best {
public:
    static BestSol obj;
    
    BestSol();
    virtual ~BestSol();
    
    virtual const char* name() const { return "BestSol";}
    virtual const char* description() const { return NULL;};
    
    virtual void services(LinkerNodes *com) throw(exception);
    virtual void load() throw(exception);
    virtual void start() throw(exception);
    
    virtual void results(LinkerResults *com) throw(exception);
    virtual void addBetter(Problem *mem, Solution *sol) throw(exception);
    
    virtual double time_now();
    virtual double time_best();
    virtual double time_after();
    
private:
    Solution *best;
    long eval_best;
    double time_init;
    double time_best_;
    double time_tot;
    
    //const uTime time = new uTimeMili();
    Problem *problem;
    nEvaluations *eval_tot;
    aStop *stop;
    StreamPrinter *com;
};
#endif	/* PBESTSOL_H */

