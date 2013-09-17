/* 
 * File:   iStopTime.h
 * Author: marcio
 *
 * Created on 10 de Abril de 2013, 14:46
 */

#ifndef ISTOPTIME_H
#define	ISTOPTIME_H

#include "aStop.h"

class iStopTime : public aStop {
public:
    iStopTime();
    virtual ~iStopTime();
    
    virtual const char* name() const;
    virtual const char* description() const;
    virtual void parameters(LinkerParameters *com) throw(exception);
    virtual void start() throw(exception);
    virtual double progress() throw(exception);
    virtual bool end() throw(exception);
private:
    double initial_time;
    //ComProgress com;
    double time;
};

#endif	/* ISTOPTIME_H */

