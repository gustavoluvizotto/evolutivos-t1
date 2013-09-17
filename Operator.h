/* 
 * File:   pOperator.h
 * Author: marcio
 *
 * Created on 13 de Março de 2013, 16:48
 */

#ifndef OPERATOR_H
#define	OPERATOR_H

#include "NodeEnd.h"
#include <stddef.h>
#include <exception>
using std::exception;

class Operator : public NodeEnd {
public:
    Operator(){};
    virtual ~Operator(){};
    virtual const char* name()const = 0;
    virtual const char* description() const{
        return NULL;
    }
    virtual void parameters(LinkerParameters *com) throw(exception){}
    virtual bool validation(LinkerValidations *com) throw(exception){}
    void load() throw(exception){}
    void start() throw(exception){}
    void results(LinkerResults *com) throw(exception){}
};

#endif	/* POPERATOR_H */

