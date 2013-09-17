/* 
 * File:   cStopAbstract.h
 * Author: andre
 *
 * Created on 13 de Dezembro de 2012, 21:10
 */

#ifndef ASTOP_H
#define	ASTOP_H

#include <exception>
#include "Node.h"

class aStop : public Node {
public:
    aStop();
    virtual ~aStop();
    
    virtual double progress() throw(exception) = 0;
    virtual bool end() throw(exception)  = 0;
    
    virtual const char* name() const = 0 ;
    virtual const char* description() const = 0;
    virtual void start() throw(exception) = 0;
    
    virtual void construct() throw(exception);
    virtual void services(LinkerNodes *com) throw(exception);
    virtual void load() throw(exception);
    virtual void parameters(LinkerParameters *com) throw(exception);
    virtual bool validation(LinkerValidations *com) throw(exception);
    virtual void results(LinkerResults *com) throw(exception);
    
private:

};

#endif	/* CSTOPABSTRACT_H */

