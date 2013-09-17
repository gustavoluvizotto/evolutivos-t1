/* 
 * File:   NodeParameter.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 22:05
 */

#ifndef NODEPARAMETER_H
#define	NODEPARAMETER_H

#include <string>
#include <exception>

#include "Node.h"

using std::string;
using std::exception;

class NodeParameter : public Node{
public:
    virtual ~NodeParameter(){};
    
    virtual const char* name()const = 0;
    virtual const char* description()const = 0;
    
    virtual void parameters(LinkerParameters *com) throw(exception) = 0;
    virtual bool validation(LinkerValidations *com) throw(exception) = 0;
    
    virtual void load() throw(exception){
    
    }
    virtual void start() throw(exception){
    
    }
    virtual void results(LinkerResults *com) throw(exception){
    
    }
};

#endif	/* NODEPARAMETER_H */

