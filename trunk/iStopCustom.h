/* 
 * File:   iStopCustom.h
 * Author: marcio
 *
 * Created on 28 de Agosto de 2013, 22:03
 */

#ifndef ISTOPCUSTOM_H
#define	ISTOPCUSTOM_H

#include "aStop.h"

class iStopCustom : public aStop {
public:
    static const iStopCustom obj;
    
    iStopCustom();
    virtual ~iStopCustom();
    
    virtual const char* name() const;
    virtual const char* description() const;
    virtual void parameters(LinkerParameters *com) throw(exception);
    virtual void start() throw(exception);
    virtual double progress() throw(exception);
    virtual bool end() throw(exception);
private:
};

#endif	/* ISTOPCUSTOM_H */

