/* 
 * File:   ComStreamAdapter.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 19:46
 */

#ifndef STREAMADAPTER_H
#define	STREAMADAPTER_H

#include <string>
#include <exception>
#include <iostream>

#include "Stream.h"

using std::string;
using std::exception;
using std::cout;
using std::endl;

class StreamAdapter : public Stream{
public:
    StreamAdapter(const string& type, const string& name);
    virtual ~StreamAdapter();
    
    /*const string& type()const throw(exception);
    const string& name()const throw(exception);
    void open() throw(exception);
    void flush() throw(exception);
    void close() throw(exception);*/
    virtual const string& type()const throw(exception);
    virtual const string& name()const throw(exception);
    virtual void open() throw(exception);
    virtual void flush() throw(exception);
    virtual void close() throw(exception);
protected:
    const string t;
    const string mk;
    bool isOpen;
};

#endif	/* COMSTREAMADAPTER_H */

