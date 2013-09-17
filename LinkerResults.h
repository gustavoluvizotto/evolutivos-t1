/* 
 * File:   ComResults.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 18:31
 */

#ifndef LINKERRESULTS_H
#define	LINKERRESULTS_H

#include <string>
#include <exception>

#include "StreamAdapter.h"

using std::string;
using std::exception;

class LinkerResults : public StreamAdapter {
public:
    LinkerResults(const string& type, const string& name):StreamAdapter(type,name){};
    virtual ~LinkerResults(){}
    virtual void writeInt(const string& name, int value) throw(exception) = 0;
    virtual void writeLong(const string& name, long value) throw(exception) = 0;
    virtual void writeDbl(const string& name, double value) throw(exception) = 0;
    virtual void writeString(const string& name, const string& value) throw(exception) = 0;
    virtual void writeFile(const string& file) throw(exception) = 0;
};

#endif	/* COMRESULTS_H */

