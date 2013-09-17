/* 
 * File:   RgxRule.cpp
 * Author: marcio
 * 
 * Created on 13 de Junho de 2013, 17:09
 */

#include "RgxRule.h"

const char* RgxRule::ANYTHING     = "(.*)";
const char* RgxRule::DIRECTORY    = "(.*[/])";
const char* RgxRule::FILE         = "(.*[^/])";
const char* RgxRule::WORD         = "([a-zA-Z_][a-zA-Z_0-9]*)";
const char* RgxRule::INT          = "(([1-9][0-9]+)|([0-9]))";

RgxRule::RgxRule(const char* regex) {
    if(regex==NULL || strlen(regex)==0){
        this->regex = RgxRule::ANYTHING;
    }else{
        this->regex = regex;
    }
    this->constraints = NULL;
    this->length = 0;
}
RgxRule::RgxRule(const char* regex, const char** constraints, int length) {
    if(regex==NULL || strlen(regex)==0){
        this->regex = RgxRule::ANYTHING;
    }else{
        this->regex = regex;
    }
    for(int i=0; i<length; i++){
        assert(!(constraints[i]==NULL));
        assert(!(strlen(constraints[i])==0));
    }
    this->constraints = constraints;
    this->length = length;
}
RgxRule::~RgxRule() {
    delete[] regex;
    delete[] regex;
    for(int i=0; i<length; i++){
        delete[] constraints[i];
    }
    delete[] constraints;
}
