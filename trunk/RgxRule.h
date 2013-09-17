/* 
 * File:   RgxRule.h
 * Author: marcio
 *
 * Created on 13 de Junho de 2013, 17:09
 */

#ifndef RGXRULE_H
#define	RGXRULE_H

#include <cstdio>
#include <cstring>
#include <assert.h>

class RgxRule {
public:
    static const char* ANYTHING;
    static const char* DIRECTORY;
    static const char* FILE;
    static const char* WORD;
    static const char* INT;
    
    RgxRule(const char* regex);
    RgxRule(const char* regex, const char** constraints, int length);
    ~RgxRule();
    
    
    const char* subject(int i) const{
        return constraints[i];
    }
    int size() const{
        return length;
    }
    const char* rgx() const{
        return regex;
    }
    static bool matches(const char* text, const char* pattern){
        //TODO FAZER MATCHES
        return true;//std::regex_match(text, pattern);
    }
    
    static const RgxRule* One(const char** extensions, int length){
        assert(!(extensions==NULL || length<1));
        for(int i=0; i<length; i++){
            assert(!(extensions[i]==NULL));
            assert(matches(extensions[i], RgxRule::WORD));
        }
        char* buffer = new char[1000];
        int n = sprintf(buffer, "(.*\\.%s)", extensions[0]);
        assert(!(n>=1000));
        for(int i=1; i<length; i++){
            n += sprintf(&(buffer[n]), "|(.*\\.%s)", extensions[i]);
            assert(!(n>=1000));
        }
        return new RgxRule(buffer);
    }
    static RgxRule** All(const char** extensions, int length){
        assert(!(extensions==NULL || length<1));
        for(int i=0; i<length; i++){
            assert(!(extensions[i]==NULL));
            assert(matches(extensions[i], RgxRule::WORD));
        }
        RgxRule** rules = new RgxRule*[length];
        for(int i=0; i<length; i++){
            char* buffer = new char[1000];
            int n = sprintf(buffer, "(.*\\.%s)", extensions[i]);
            assert(!(n>=1000));
            rules[i] = new RgxRule(buffer);
        }
        return rules;
    }
    static const RgxRule* Directory(const char** constraints, int length) {
        return new RgxRule(RgxRule::DIRECTORY, constraints, length);
    }
private:
    const char* regex;
    const char** constraints;
    int length;
};

#endif	/* RGXRULE_H */

