/* 
 * File:   NodeSingle.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 22:07
 */

#ifndef NODESINGLE_H
#define	NODESINGLE_H

#include <string>
#include <exception>

#include "NodeEnd.h"

using std::string;
using std::exception;

class NodeSingle : public NodeEnd{
public:
    virtual ~NodeSingle(){}
    
    virtual const char* name()const = 0;
    virtual const char* description()const = 0;
    
    void start() throw(exception) = 0;
    
    void parameters(LinkerParameters *com) throw(exception){
        
    }
    bool validation(LinkerValidations *com) throw(exception){
        
    }
    void load() throw(exception){
        
    }
    void results(LinkerResults *com) throw(exception){
        
    }
    void services(LinkerNodes *com) throw(exception){
        
    };
};

#endif	/* NODESINGLE_H */

