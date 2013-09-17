/* 
 * File:   NodeEnd.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 21:18
 */

#ifndef NODEEND_H
#define	NODEEND_H

#include <string>
#include <exception>

#include "Node.h"

using std::string;
using std::exception;

class NodeEnd : public Node{
public:
    virtual ~NodeEnd(){}
    
    virtual const char* name()const = 0;
    virtual const char* description()const = 0;
    
    virtual void parameters(LinkerParameters *com) throw(exception) = 0;
    virtual bool validation(LinkerValidations *com) throw(exception) = 0;
    virtual void load() throw(exception) = 0;
    virtual void start() throw(exception) = 0;
    virtual void results(LinkerResults *com) throw(exception) = 0;
    
    void services(LinkerNodes *com) throw(exception){
        
    };
};

#endif	/* NODEEND_H */

