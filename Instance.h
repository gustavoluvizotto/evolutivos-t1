/* 
 * File:   pInstance.h
 * Author: andre
 *
 * Created on 30 de Janeiro de 2013, 15:13
 */

#ifndef INSTANCE_H
#define	INSTANCE_H

#include "NodeEnd.h"


class Instance : public NodeEnd{
public:
    Instance();
    virtual ~Instance();
    
    virtual const char* name()const = 0;
    virtual const char* description()const = 0;
    
    virtual void parameters(LinkerParameters *com) throw(exception);
    virtual bool validation(LinkerValidations *com) throw(exception);
    virtual void load() throw(exception);
    virtual void start() throw(exception);
    void results(LinkerResults *com) throw(exception);
private:

};

#endif	/* PINSTANCE_H */

