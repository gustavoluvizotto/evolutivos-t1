/* 
 * File:   MetaHeuristic.h
 * Author: andre
 *
 * Created on 12 de Dezembro de 2012, 16:55
 */

#ifndef METAHEURISTIC_H
#define	METAHEURISTIC_H

#include <exception>
#include "Run.h"
using std::exception;

class MetaHeuristic : public Run{
public:
    MetaHeuristic(){}
    virtual ~MetaHeuristic(){}
    virtual void parameters(LinkerParameters *com) throw(exception) {}
    virtual bool validation(LinkerValidations *com) throw(exception) {return true;}
    virtual void load() throw(exception) {}
    virtual void start() throw(exception) {}
    virtual void results(LinkerResults *com) throw(exception) {}
    
    virtual const char* name()const = 0;
    virtual const char* description()const = 0;
    virtual void services(LinkerNodes *com) throw(exception) = 0;
    virtual void execute() throw(exception) = 0;
private:

};

#endif	/* METAHEURISTIC_H */
