/* 
 * File:   ComStream.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 18:46
 */

#ifndef STREAM_H
#define	STREAM_H

#include <string>
#include <exception>

using std::string;
using std::exception;

class Stream {
public:
    virtual ~Stream(){};
    
    virtual const string& type()const throw(exception) = 0;
    virtual const string& name()const throw(exception) = 0;
    virtual void open() throw(exception) = 0;
    virtual void flush() throw(exception) = 0;
    virtual void close() throw(exception) = 0;
    
    
    /*
    virtual const string& type()const throw(exception){};// = 0;
    virtual const string& name()const throw(exception){};// = 0;
    virtual void open() throw(exception){};// = 0;
    virtual void flush() throw(exception){};// = 0;
    virtual void close() throw(exception){};// = 0;
    */
};

#endif	/* COMSTREAM_H */

