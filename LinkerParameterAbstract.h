/* 
 * File:   ComParameterAbstract.h
 * Author: marcio
 *
 * Created on 13 de Junho de 2013, 16:37
 */

#ifndef LINKERPARAMETERABSTRACT_H
#define	LINKERPARAMETERABSTRACT_H

#include "LinkerParameters.h"
#include "RgxRule.h"


class LinkerParameterAbstract : public LinkerParameters{
public:
    virtual int Int(const char* name, int init) throw(exception);
    virtual int Int(const char* name, int init, int min, int max) throw(exception);
     
    virtual long long Long(const char* name, long long init) throw(exception);
    virtual long long Long(const char* name, long long init, long long min, long long max) throw(exception);
     
    virtual double Dbl(const char* name, double init) throw(exception);
    virtual double Dbl(const char* name, double init, double min, double max) throw(exception);
     
    virtual const char* String(const char* name, const char* init) throw(exception);
    virtual const char* Regex(const char* name, const char* init, const char* regex) throw(exception);
 
    virtual const char* File(const char* name, const char* extension) throw(exception);
    virtual const char* File(const char* name, const char** extensions, int length) throw(exception);
    virtual const char* File(const char* name, const char* description, const char** extensions, int length) throw(exception);
    virtual const char** Files(const char* name, const char** extensions, int length) throw(exception);
    virtual const char** Files(const char* name, const char* description, const char** extensions, int length) throw(exception);
    virtual const char* Directory(const char* name) throw(exception);
    virtual const char* Directory(const char* name, const char* description) throw(exception);
    virtual const char* Directory(const char* name, const char* description, const char** constraints, int length) throw(exception);
    virtual const char* FileRgx(const char* name, const char* description, const char* regex, const char** constraints, int length) throw(exception);
    virtual const char* FileRgx(const char* name, const RgxRule* rule) throw(exception);
    virtual const char** FilesRgx(const char* name, RgxRule** rules, int length) throw(exception);
    
    virtual int Int(const char* name, int init, int min, int max, const char* description) throw(exception) = 0;
    virtual long long Long(const char* name, long long init, long long min, long long max, const char* description) throw(exception) = 0;
    virtual double Dbl(const char* name, double init, double min, double max, const char* description) throw(exception) = 0;
    virtual const char* String(const char* name, const char* init, const char* description) throw(exception) = 0;
    virtual const char* Regex(const char* name, const char* init, const char* regex, const char* description) throw(exception) = 0;
    virtual const char* FileRgx(const char* name, const char* description, const RgxRule* rule) throw(exception) = 0; 
    virtual const char** FilesRgx(const char* name, const char* description, RgxRule** rules, int length) throw(exception) = 0;    
private:

};

#endif	/* COMPARAMETERABSTRACT_H */

