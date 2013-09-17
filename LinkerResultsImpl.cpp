/* 
 * File:   ComResultsImpl.cpp
 * Author: marcio
 * 
 * Created on 16 de Dezembro de 2012, 16:32
 */

#include "LinkerResultsImpl.h"
#include "ComDefines.h"
#include "uException.h"

#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

LinkerResultsImpl::LinkerResultsImpl()
    : LinkerResults(COM::WRITE, COM::RESULTS) {}

LinkerResultsImpl::~LinkerResultsImpl() {}

void LinkerResultsImpl::writeObj(const string& type, const string& name, const string& value) throw (exception){
    cout <<COM::NAME<<mk <<COM::ARG<<type <<COM::ARG<<name <<COM::ARG<<value << endl; cout.flush();
    #ifdef PRINT
        cout << "\t" << mk << " " << type << " " << name << " =  "<<value<< " ;" <<endl;  cout.flush();
    #endif
}
void LinkerResultsImpl::writeInt(const string& name, int value) throw(exception){
    ostringstream out; out << value;
    writeObj(COM::INT, name, out.str());
}
void LinkerResultsImpl::writeLong(const string& name, long value) throw(exception){
    ostringstream out; out << value;
    writeObj(COM::LONG, name, out.str());
}
void LinkerResultsImpl::writeDbl(const string& name, double value) throw(exception){
    ostringstream out; out << value;
    writeObj(COM::DOUBLE, name, out.str());
}
void LinkerResultsImpl::writeString(const string& name, const string& value) throw(exception){
    ostringstream out; out << value;
    writeObj(COM::STRING, name, out.str());
}
void LinkerResultsImpl::writeFile(const string& file) throw(exception){
    throw uException("in ComResultsImpl::writeFile, Not supported yet.");
}

