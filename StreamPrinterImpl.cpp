/* 
 * File:   ComPrinterImpl.cpp
 * Author: marcio
 * 
 * Created on 16 de Dezembro de 2012, 15:52
 */

#include "StreamPrinterImpl.h"
#include "ComDefines.h"

#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

StreamPrinterImpl::StreamPrinterImpl(const string& mk_name)
    : StreamPrinter(COM::STREAM, mk_name) {}

StreamPrinterImpl::~StreamPrinterImpl() {}

void StreamPrinterImpl::printObj(const string& type, const string& name, const string& format, const string& value) throw (exception){
    cout <<COM::NAME<<mk <<COM::ARG<<type <<COM::ARG<<name <<COM::ARG<<format <<COM::ARG<<value << endl;
    #ifdef PRINT
        cout << "\t" << mk << " " << type << " " << name << " =  "<<value<< " ;" <<endl;
    #endif
}

void StreamPrinterImpl::printInt(const string& name, int value) throw (exception){
    ostringstream out; out << value;
    printObj(COM::INT, name, "%12d", out.str());
}
void StreamPrinterImpl::printInt(const string& name, const string& format, int value) throw (exception){
    ostringstream out; out << value;
    printObj(COM::INT, name, format, out.str());
}
void StreamPrinterImpl::printLong(const string& name, long value) throw (exception){
    ostringstream out; out << value;
    printObj(COM::LONG, name, "%12d", out.str());
}
void StreamPrinterImpl::printLong(const string& name, const string& format, long value) throw (exception){
    ostringstream out; out << value;
    printObj(COM::LONG, name, format, out.str());
}

void StreamPrinterImpl::printDbl(const string& name, double value) throw (exception){
    ostringstream out; out << value;
    printObj(COM::DOUBLE, name, "%12g", out.str());
}
void StreamPrinterImpl::printDbl(const string& name, const string& format, double value) throw (exception){
    ostringstream out; out << value;
    printObj(COM::DOUBLE, name, format, out.str());
}

void StreamPrinterImpl::printString(const string& name, const string& value) throw (exception){
    ostringstream out; out << value;
    printObj(COM::STRING, name, "%12s", out.str());
}
void StreamPrinterImpl::printString(const string& name, const string& format, const string& value) throw (exception){
    ostringstream out; out << value;
    printObj(COM::STRING, name, format, out.str());
}


