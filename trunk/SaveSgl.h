/* 
 * File:   wWindowsSgl.h
 * Author: marcio
 *
 * Created on 10 de Dezembro de 2012, 00:33
 */

#ifndef SAVESGL_H
#define	SAVESGL_H

#include <sstream>
#include <string>
#include <climits>
#include <cfloat>
#include "LinkerParameterAbstract.h"
#include "uException.h"

#include <assert.h>

using std::ostringstream;
using std::endl;
using std::string;

class SaveSgl : public LinkerParameterAbstract{
public:
    SaveSgl() : output(), count(0) {}
    
    virtual ~SaveSgl(){}
    
    int size() const {
        return count;
    }
    int Int(const char* name, int init, int min, int max, const char* description) throw(exception){
        assert(!(name==NULL));
        description = description==NULL ? "null" : description;
        output  << "<type>"             << endl
                << "Int"                << endl
                << "<name>"             << endl
                << name                 << endl
                << "<init>"             << endl
                << init                 << endl
                << "<min>"              << endl
                << min                  << endl
                << "<max>"              << endl
                << max                  << endl
                << "<description>"      << endl
                << description          << endl;
        count++;
        return 0;
    }
    long long Long(const char* name, long long init, long long min, long long max, const char* description) throw(exception){
        assert(!(name==NULL));
        description = description==NULL ? "null" : description;
        output  << "<type>"             << endl
                << "Int"                << endl
                << "<name>"             << endl
                << name                 << endl
                << "<init>"             << endl
                << init                 << endl
                << "<min>"              << endl
                << min                  << endl
                << "<max>"              << endl
                << max                  << endl
                << "<description>"      << endl
                << description          << endl;
        count++;
        return 0;
    }
    double Dbl(const char* name, double init, double min, double max, const char* description) throw(exception){
        assert(!(name==NULL));
        description = description==NULL ? "null" : description;
        output  << "<type>"             << endl
                << "Dbl"                << endl
                << "<name>"             << endl
                << name                 << endl
                << "<init>"             << endl
                << init                 << endl
                << "<min>"              << endl
                << min                  << endl
                << "<max>"              << endl
                << max                  << endl
                << "<description>"      << endl
                << description          << endl;
        count++;
        return 0;
    }
    const char* String(const char* name, const char* init, const char* description) throw(exception){
        assert(!(name==NULL));
        assert(!(init==NULL));
        description = description==NULL ? "null" : description;
        output  << "<type>"             << endl
                << "String"             << endl
                << "<name>"             << endl
                << name                 << endl
                << "<init>"             << endl
                << init                 << endl
                << "<description>"      << endl
                << description          << endl;
        count++;
        return NULL;
    }
    const char* Regex(const char* name, const char* init, const char* regex, const char* description) throw(exception){
        assert(!(name==NULL));
        assert(!(init==NULL));
        assert(!(regex==NULL));
        description = description==NULL ? "null" : description;
        output  << "<type>"             << endl
                << "Regex"              << endl
                << "<name>"             << endl
                << name                 << endl
                << "<init>"             << endl
                << init                 << endl
                << "<regex>"            << endl
                << regex                << endl
                << "<description>"      << endl
                << description          << endl;
        count++;
        return NULL;
    }
    const char* FileRgx(const char* name, const char* description, const RgxRule* rule) throw(exception){
        assert(!(name==NULL));
        assert(!(rule==NULL));
        description = description==NULL ? "null" : description;
        output  << "<type>"             << endl
                << "FileRgx"            << endl
                << "<name>"             << endl
                << name                 << endl
                << "<description>"      << endl
                << description          << endl
                << "<regex>"            << endl
                << rule->rgx()          << endl
                << "<constrants>"      << endl
                << rule->size()        << endl;
        for(int i=0; i<rule->size(); i++){
            output  << rule->subject(i) << endl;
        }
        count++;
        return NULL;
    }
    const char** FilesRgx(const char* name, const char* description, RgxRule** rules, int length) throw(exception){
        assert(!(name==NULL));
        assert(!(rules==NULL));
        assert(!(length<1));
        for(int i=0; i<length; i++){
            assert(rules[i]==NULL);
        }
        description = description==NULL ? "null" : description;
        output  << "<type>"                               << endl
                << "FilesRgx"                             << endl
                << "<name>"                               << endl
                << name                                   << endl
                << "<description>"                        << endl
                << description                            << endl
                << "<--------------rules---------------->"<< endl
                << length                                 << endl;
        for(int i=0; i<length; i++){
            output      << "<regex>"                << endl
                        << rules[i]->rgx()          << endl
                        << rules[i]->size()         << endl;
            for(int j=0; j<rules[i]->size(); j++){
                output  << rules[i]->subject(j) << endl;
            }
        }
        count++;
        return NULL;
    }
    const char* str(){
        return output.str().c_str();
    }
private:
    ostringstream output;
    int count;
};

#endif	/* WWINDOWSSGL_H */

