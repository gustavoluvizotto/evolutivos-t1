/* 
 * File:   WinParams.cpp
 * Author: marcio
 * 
 * Created on 14 de Dezembro de 2012, 15:42
 */

#include "WinParams.h"
#include "ComDefines.h"
#include "Serv.h"

#include <cstdlib>
#include <cstring>
#include <string>
#include <assert.h>

using std::string;
using std::atof;
using std::atoi;
using std::atol;


WinParams::WinParams(const char* in) : get(0), input(in) {
    assert(!(in==NULL));
    this->length = strlen(in);
}
WinParams::~WinParams() {
}

void WinParams::start(Serv* serv){
    assert(!(serv==NULL));
    this->serv = serv;
    this->get = 0;
}

int WinParams::Int(const char* name, int init, int min, int max, const char* description) throw(exception){
    int v= atoi(serv->params[get++].c_str());
    #ifdef PRINT
        cout << "\tint " << name << "\t = " << v<<endl; cout.flush();
    #endif
    return v;
}
long long WinParams::Long(const char* name, long long init, long long min, long long max, const char* description) throw(exception){
    long long v= atoll(serv->params[get++].c_str());
    #ifdef PRINT
        cout << "\tlong " << name << "\t = " << v<<endl; cout.flush();
    #endif
    return v;
}
double WinParams::Dbl(const char* name, double init, double min, double max, const char* description) throw(exception){
    double v= atof(serv->params[get++].c_str());
    #ifdef PRINT
        cout << "\tdouble " << name << "\t = " << v<<endl; cout.flush();
    #endif
    return v;
}
const char* WinParams::String(const char* name, const char* init, const char* description) throw(exception){
    const char* v= serv->params[get++].c_str();
    #ifdef PRINT
        cout << "\tstring " << name << "\t = " << v<<endl; cout.flush();
    #endif
    return v;
}
const char* WinParams::Regex(const char* name, const char* init, const char* regex, const char* description) throw(exception){
    const char* v= serv->params[get++].c_str();
    #ifdef PRINT
        cout << "\tregex " << name << "\t = " << v<<endl; cout.flush();
    #endif
    return v;
}
const char* WinParams::FileRgx(const char* name, const char* description, const RgxRule* rule) throw(exception){
    const char* v= serv->params[get++].c_str();
    int size = length + strlen(v) + 1;
    char* temp = new char[size];
    strcpy(temp,input);
    strncat(temp, v, size);
    
    #ifdef PRINT
        cout << "\tfilergx " << name << "\t = " << temp <<endl; cout.flush();
    #endif
    return temp;
}
const char** WinParams::FilesRgx(const char* name, const char* description, RgxRule** rules, int length) throw(exception){
    const char* str= serv->params[get++].c_str();
    
    char temp[strlen(str)];
    strcpy(temp, str);
    
    const char** v = new const char*[length];
    char * pch;
    int i=0;
    pch = strtok (temp,";");
    while (pch != NULL){
        int size = length + strlen(pch) + 1;
        char* aux = new char[size];
        strcpy(aux,input);
        strncat(aux, pch, size);
        v[i] = aux;
        pch = strtok (NULL, ";");
        i++;
        assert(!(i>length));
    }
    assert(!(i<length));
    return v;
}


