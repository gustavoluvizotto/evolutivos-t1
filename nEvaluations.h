/* 
 * File:   pEvaluations.h
 * Author: andre
 *
 * Created on 14 de Dezembro de 2012, 16:57
 */

#ifndef NEVALUATIONS_H
#define	NEVALUATIONS_H

#include <exception>
#include "NodeSingle.h"


class nEvaluations: public NodeSingle {
public:
    static nEvaluations obj;
    
    nEvaluations();    
    virtual ~nEvaluations();
    
    void update(){evaluations++;}
    long value(){return evaluations;}
    
    
    void start() throw(exception) {evaluations = 0;}    
    const char* name()const {return "Evaluations";}    
    const char* description()const {return NULL;}
    
private:
    long evaluations;
};
#endif	/* PEVALUATIONS_H */

