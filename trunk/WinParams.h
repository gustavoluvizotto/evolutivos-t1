/* 
 * File:   WinParams.h
 * Author: marcio
 *
 * Created on 14 de Dezembro de 2012, 15:42
 */

#ifndef WINPARAMS_H
#define	WINPARAMS_H

#include <string>
#include <vector>

#include "LinkerParameterAbstract.h"

class Serv;

using std::string;
using std::vector;

class WinParams : public LinkerParameterAbstract{
public:
    WinParams(const char* input);
    virtual ~WinParams();
    
    void start(Serv* serv);
    
    int Int(const char* name, int init, int min, int max, const char* description) throw(exception);
    long long Long(const char* name, long long init, long long min, long long max, const char* description) throw(exception);
    double Dbl(const char* name, double init, double min, double max, const char* description) throw(exception);
    const char* String(const char* name, const char* init, const char* description) throw(exception);
    const char* Regex(const char* name, const char* init, const char* regex, const char* description) throw(exception);
    const char* FileRgx(const char* name, const char* description, const RgxRule* rule) throw(exception); 
    const char** FilesRgx(const char* name, const char* description, RgxRule** rules, int length) throw(exception);
private:
    Serv* serv;
    int get;
    int length;
    const char* input;
};

#endif	/* WINPARAMS_H */

