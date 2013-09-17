/* 
 * File:   ComPrinter.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 18:55
 */

#ifndef STREAMPRINTER_H
#define	STREAMPRINTER_H

#include <string>
#include <exception>

#include "StreamAdapter.h"

using std::string;
using std::exception;

class StreamPrinter : public StreamAdapter{
public:
    StreamPrinter(const string& type, const string& name):StreamAdapter(type,name){};
    virtual ~StreamPrinter(){}
    virtual void printInt(const string& name, int value) throw (exception) = 0;
    virtual void printInt(const string& name, const string& format, int value) throw (exception) = 0;
    
    virtual void printLong(const string& name, long value) throw (exception) = 0;
    virtual void printLong(const string& name, const string& format, long value) throw (exception) = 0;
    
    virtual void printDbl(const string& name, double value) throw (exception) = 0;
    virtual void printDbl(const string& name, const string& format, double value) throw (exception) = 0;
    
    virtual void printString(const string& name, const string& value) throw (exception) = 0;
    virtual void printString(const string& name, const string& format, const string& value) throw (exception) = 0;
};

#endif	/* COMPRINTER_H */

