/* 
 * File:   NodeExecutable.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 21:28
 */

#ifndef RUN_H
#define	RUN_H

#include "Node.h"

using std::string;
using std::exception;

class Run : public Node{
public:
    Run(){}
    virtual ~Run(){}
    
    virtual const char* name()const = 0;
    virtual const char* description()const = 0;

    virtual void services(LinkerNodes *com) throw(exception) = 0;
    virtual void parameters(LinkerParameters *com) throw(exception) = 0;
    virtual bool validation(LinkerValidations *com) throw(exception) = 0;
    virtual void load() throw(exception) = 0;
    virtual void start() throw(exception) = 0;
    virtual void results(LinkerResults *com) throw(exception) = 0;
    
    virtual void execute() throw(exception) = 0;
};

#endif	/* NODEEXECUTABLE_H */

