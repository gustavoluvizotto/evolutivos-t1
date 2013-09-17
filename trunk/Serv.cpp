/* 
 * File:   Serv.cpp
 * Author: marcio
 * 
 * Created on 14 de Dezembro de 2012, 20:01
 */

#include "Serv.h"
#include "ComDefines.h"

Serv::Serv(istream& input) {
    int id, type, n_param;
    NEXT_TRASH(input);
    NEXT_INT(input, id);
    
    NEXT_TRASH(input);
    NEXT_INT(input, type);
    
    NEXT_TRASH(input);
    NEXT_STR(input, s);
    
    NEXT_TRASH(input);
    NEXT_INT(input, n_param);
    
    string aux;
    for(int i=0; i<n_param; i++){
        NEXT_STR(input, aux);
        params.push_back(aux);
    }
}
Serv::~Serv() {
}
const string& Serv::name() const{
    return s;
}

