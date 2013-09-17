/* 
 * File:   wWindowsPof.h
 * Author: marcio
 *
 * Created on 12 de Dezembro de 2012, 22:44
 */

#ifndef SAVEPOF_H
#define	SAVEPOF_H

#include <sstream>
#include <string>
#include <climits>
#include <cfloat>
#include "LinkerParameterAbstract.h"
#include "uException.h"
#include "RgxRule.h"
#include "ComDefines.h"

using std::ostringstream;
using std::endl;
using std::string;

class SavePof : public LinkerParameterAbstract{
public:
    SavePof() : output(), count(0) {}
    
    virtual ~SavePof(){};
    
    int Int(const char* name, int init, int min, int max, const char* description) throw(exception){
        DEBUGF_6("Int(%s,%d,%d,%d,%s)\n", name, init, min, max, description);
        assert(!(name==NULL));
        description = description==NULL ? "null" : description;
        output  << "\t\tInt [name = '"<<name<<"', init = "<<init<<", min = "<<min<<", max = "<<max<<", description = '"<<description<<"']"<<endl; 
        count++;
        return 0;
    }
    long long Long(const char* name, long long init, long long min, long long max, const char* description) throw(exception){
        DEBUGF_6("Long(%s,%lld,%lld,%lld,%s)\n", name, init, min, max, description);
        assert(!(name==NULL));
        description = description==NULL ? "null" : description;
        output  << "\t\tLong [name = '"<<name<<"', init = "<<init<<", min = "<<min<<", max = "<<max<<", description = '"<<description<<"']"<<endl;
        count++;
        return 0;
    }
    double Dbl(const char* name, double init, double min, double max, const char* description) throw(exception){
        DEBUGF_6("Dbl(%s,%g,%g,%g,%s)\n", name, init, min, max, description);
        assert(!(name==NULL));
        description = description==NULL ? "null" : description;
        output  << "\t\tDbl [name = '"<<name<<"', init = "<<init<<", min = "<<min<<", max = "<<max<<", description = '"<<description<<"']"<<endl;
        count++;
        return 0;
    }
    const char* String(const char* name, const char* init, const char* description) throw(exception){
        DEBUGF_4("String(%s,%s,%s)\n", name, init, description);
        assert(!(name==NULL));
        assert(!(init==NULL));
        description = description==NULL ? "null" : description;
        output  << "\t\tString [name = '"<<name<<"', init = "<<init<<", description = '"<<description<<"']"<<endl;
        count++;
        return NULL;
    }
    const char* Regex(const char* name, const char* init, const char* regex, const char* description) throw(exception){
        DEBUGF_5("Regex(%s,%s,%s,%s)\n", name, init, regex, description);
        assert(!(name==NULL));
        assert(!(init==NULL));
        assert(!(regex==NULL));
        description = description==NULL ? "null" : description;
        output  << "\t\tRegex [name = '"<<name<<"', init = "<<init<<"', regex = "<<regex<<", description = '"<<description<<"']"<<endl;
        count++;
        return NULL;
    }
    const char* FileRgx(const char* name, const char* description, const RgxRule* rule) throw(exception){
        DEBUGF_5("FileRgx(%s,%s,%s,%d)\n", name, description, rule->rgx(), rule->size());
        assert(!(name==NULL));
        assert(!(rule==NULL));
        description = description==NULL ? "null" : description;
        output  << "\t\tFileRgx [name = '"<<name<<"', description = '"<<description<<"', regex = "<<rule->rgx()<<", constrants = ";
        if(rule->size()<1){
            output << "null]" << endl;
        }else if(rule->size()==1){
            output << "{'" << rule->subject(0) << "'}]" << endl;
        }else{
            output << "{'" << rule->subject(0);
            for(int i=1; i<rule->size(); i++){
                output  << "','" << rule->subject(i);
            }
            output << "'}]" << endl;
        }
        count++;
        return NULL;
    }
    const char** FilesRgx(const char* name, const char* description, RgxRule** rules, int length) throw(exception){
        DEBUGF_4("FilesRgx(%s,%s,%d)\n", name, description, length);
        assert(!(name==NULL));
        assert(!(rules==NULL));
        assert(!(length<1));
        for(int i=0; i<length; i++){
            assert(!(rules[i]==NULL));
        }
        description = description==NULL ? "null" : description;
        
        output  << "\t\tFilesRgx [name = '"<<name<<"', description = '"<<description<<"', rules = ";
        if(length==1){
            output << "{regex = '" << rules[0]->rgx() << "', constrants = ";
            if(rules[0]->size()<1){
                output << "null}";
            }else if(rules[0]->size()==1){
                output << "{'" << rules[0]->subject(0) << "'}";
            }else{
                output << "{'" << rules[0]->subject(0);
                for(int j=1; j<rules[0]->size(); j++){
                    output  << "','" << rules[0]->subject(j); 
                }
                output << "'}";
            }
        }else{
            output << "{";
            for(int i=1; i<length; i++){
                output << "{regex = '" << rules[i]->rgx() << "', constrants = ";
                if(rules[i]->size()<1){
                    output << "null}";
                }else if(rules[i]->size()==1){
                    output << "{'" << rules[i]->subject(0) << "'}";
                }else{
                    output << "{'" << rules[i]->subject(0);
                    for(int j=1; j<rules[i]->size(); j++){
                        output  << "','" << rules[i]->subject(j); 
                    }
                    output << "'}";
                }
            }
            output << "}";
        }
        output << "]" << endl;
        count++;
        return NULL;
    }
    
    int size() const 
    MEMBER
        RETURN count;
    END
    
    const char* str()
    MEMBER
        RETURN output.str().c_str();
    END
private:
    ostringstream output;
    int count;
};

#endif	/* WWINDOWSPOF_H */

