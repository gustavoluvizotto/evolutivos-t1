/* 
 * File:   ComDefines.cpp
 * Author: marcio
 * 
 * Created on 14 de Dezembro de 2012, 20:30
 */

#include "ComDefines.h"
#include "StreamPrinter.h"
#include "StreamProgress.h"
#include "LinkerResults.h"
#include "LinkerResultsImpl.h"
#include "StreamPrinterImpl.h"
#include "StreamProgressImpl.h"
#include "uException.h"

#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;

class Communication{
    friend StreamPrinter* COM::mkPrinter(const string& mk_name) throw (exception);
    friend StreamProgress* COM::mkProgress(const string& mk_name) throw (exception);
    friend LinkerResults* COM::results() throw (exception);
    friend void COM::closeAll() throw (exception);
public:
    Communication();
    virtual ~Communication();
    
private:
    vector<string> names;
    LinkerResultsImpl* results;
    
    void register_name(const string& name) throw (exception);
};



namespace COM{
    const string NAME = "#";
    const string ARG = "$";
    
    const string INT = "int";
    const string LONG = "long";
    const string DOUBLE = "dbl";
    const string STRING = "str";
    
    const string RESULTS = "results";
    const string PROGRESS = "progress";
    const string STREAM = "stream";
    const string WRITE = "write";
    
    const string OPEN = "open";
    const string CLOSE = "close";
    const string OUTPUT = "output";
    const string ERROR = "error";
    
    Communication com;
}

namespace ComDefines{
    int trash_size = 1000;
    char trash[1000];
}

Communication::Communication():results(NULL){}
Communication::~Communication(){}
void Communication::register_name(const string& name) throw (exception){
    if(names.empty()){//reserved keys
        names.push_back(COM::OPEN);
        names.push_back(COM::CLOSE);
        names.push_back(COM::OUTPUT);
        names.push_back(COM::ERROR);
        //names.push_back(COM::RESULTS);
    }
    if(find(names, name)){
        ostringstream out;
        out << "repeat name = '" << name << "' in "<<names;
        throw uException(out.str());
    }
    names.push_back(name);
}

StreamPrinter* COM::mkPrinter(const string& mk_name) throw (exception){
    com.register_name(mk_name);
    return (StreamPrinter*)(new StreamPrinterImpl(mk_name)); 
}
StreamProgress* COM::mkProgress(const string& mk_name) throw (exception){
    com.register_name(mk_name);
    return (StreamProgress*)(new StreamProgressImpl(mk_name));
}
LinkerResults* COM::results() throw (exception){
    if(com.results==NULL){
        com.register_name(COM::RESULTS);
        com.results = new LinkerResultsImpl();
    }
    return (LinkerResults*)(com.results); 
}
void COM::closeAll() throw (exception){
    com.results->close();
}

