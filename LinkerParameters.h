/* 
 * File:   ComParameters.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 18:04
 */

#ifndef LINKERPARAMETERS_H
#define	LINKERPARAMETERS_H

#include "RgxRule.h"

#include <string>
#include <vector>
#include <exception>

using std::string;
using std::vector;
using std::exception;

class LinkerParameters {
public:
    virtual ~LinkerParameters(){}
    
    virtual int Int(const char* name, int init) throw(exception) = 0;
    virtual int Int(const char* name, int init, int min, int max) throw(exception) = 0;
     
    virtual long long Long(const char* name, long long init) throw(exception) = 0;
    virtual long long Long(const char* name, long long init, long long min, long long max) throw(exception) = 0;
     
    virtual double Dbl(const char* name, double init) throw(exception) = 0;
    virtual double Dbl(const char* name, double init, double min, double max) throw(exception) = 0;
     
    virtual const char* String(const char* name, const char* init) throw(exception) = 0;
    virtual const char* Regex(const char* name, const char* init, const char* regex) throw(exception) = 0;
 
    virtual const char* File(const char* name, const char* extension) throw(exception) = 0;
    virtual const char* File(const char* name, const char** extensions, int length) throw(exception) = 0;
    virtual const char* File(const char* name, const char* description, const char** extensions, int length) throw(exception) = 0;
    virtual const char** Files(const char* name, const char** extensions, int length) throw(exception) = 0;
    virtual const char** Files(const char* name, const char* description, const char** extensions, int length) throw(exception) = 0;
    virtual const char* Directory(const char* name) throw(exception) = 0;
    virtual const char* Directory(const char* name, const char* description) throw(exception) = 0;
    virtual const char* Directory(const char* name, const char* description, const char** constraints, int length) throw(exception) = 0;
    virtual const char* FileRgx(const char* name, const char* description, const char* regex, const char** constraints, int length) throw(exception) = 0;
    virtual const char* FileRgx(const char* name, const RgxRule* rule) throw(exception) = 0;
    virtual const char** FilesRgx(const char* name, RgxRule** rules, int length) throw(exception) = 0;
    
    virtual int Int(const char* name, int init, int min, int max, const char* description) throw(exception) = 0;
    virtual long long Long(const char* name, long long init, long long min, long long max, const char* description) throw(exception) = 0;
    virtual double Dbl(const char* name, double init, double min, double max, const char* description) throw(exception) = 0;
    virtual const char* String(const char* name, const char* init, const char* description) throw(exception) = 0;
    virtual const char* Regex(const char* name, const char* init, const char* regex, const char* description) throw(exception) = 0;
    virtual const char* FileRgx(const char* name, const char* description, const RgxRule* rule) throw(exception) = 0; 
    virtual const char** FilesRgx(const char* name, const char* description, RgxRule** rules, int length) throw(exception) = 0; 
};

#endif	/* COMPARAMETERS_H */

