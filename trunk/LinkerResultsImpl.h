/* 
 * File:   ComResultsImpl.h
 * Author: marcio
 *
 * Created on 16 de Dezembro de 2012, 16:32
 */

#ifndef LINKERRESULTSIMPL_H
#define	LINKERRESULTSIMPL_H

#include "LinkerResults.h"

#include <string>
using std::string;

class LinkerResultsImpl : public LinkerResults{
public:
    LinkerResultsImpl();
    virtual ~LinkerResultsImpl();
    void writeInt(const string& name, int value) throw(exception);
    void writeLong(const string& name, long value) throw(exception);
    void writeDbl(const string& name, double value) throw(exception);
    void writeString(const string& name, const string& value) throw(exception);
    void writeFile(const string& file) throw(exception);
private:
    void writeObj(const string& type, const string& name, const string& value) throw (exception);
};

#endif	/* COMRESULTSIMPL_H */

