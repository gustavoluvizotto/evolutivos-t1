/* 
 * File:   ComPrinterImpl.h
 * Author: marcio
 *
 * Created on 16 de Dezembro de 2012, 15:52
 */

#ifndef STREAMPRINTERIMPL_H
#define	STREAMPRINTERIMPL_H

#include "StreamPrinter.h"

class StreamPrinterImpl : public StreamPrinter{
public:
    StreamPrinterImpl(const string& mk_name);
    virtual ~StreamPrinterImpl();
    
    void printInt(const string& name, int value) throw (exception);
    void printInt(const string& name, const string& format, int value) throw (exception);
    void printLong(const string& name, long value) throw (exception);
    void printLong(const string& name, const string& format, long value) throw (exception);
    void printDbl(const string& name, double value) throw (exception);
    void printDbl(const string& name, const string& format, double value) throw (exception);
    void printString(const string& name, const string& value) throw (exception);
    void printString(const string& name, const string& format, const string& value) throw (exception);
private:
    void printObj(const string& type, const string& name, const string& format, const string& value) throw (exception);
};

#endif	/* COMPRINTERIMPL_H */

