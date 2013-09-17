/* 
 * File:   ComProgress.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 19:31
 */

#ifndef STREAMPROGRESS_H
#define	STREAMPROGRESS_H

#include <exception>

#include "StreamAdapter.h"


using std::exception;

class StreamProgress : public StreamAdapter{
public:
    StreamProgress(const string& type, const string& name):StreamAdapter(type,name){};
    virtual ~StreamProgress(){}
    virtual void progress(double value) throw(exception) = 0;
    virtual void restart() throw(exception) = 0;
};

#endif	/* COMPROGRESS_H */

