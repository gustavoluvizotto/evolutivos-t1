/* 
 * File:   Exception.cpp
 * Author: marcio
 * 
 * Created on 9 de Dezembro de 2012, 20:18
 */

#include "uException.h"

uException::uException(const string &msg):s(msg){}
uException::uException(const uException& orig):s(orig.s){}
const char* uException::what() const throw(){
    return s.c_str();
}
const string& uException::msg() const throw(){
    return s;
}

namespace EXCEPTION{
    bool frist = true;
    vector<string> stack;
}

