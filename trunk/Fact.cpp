/* 
 * File:   Fact.cpp
 * Author: marcio
 * 
 * Created on 14 de Dezembro de 2012, 20:32
 */

#include "Fact.h"
#include "ComDefines.h"

Fact::Fact(istream& input) {
    int id, type;
    NEXT_TRASH(input);
    NEXT_INT(input, id);
    
    NEXT_TRASH(input);
    NEXT_INT(input, type);
    
    NEXT_TRASH(input);
    NEXT_STR(input, s);
    
    NEXT_TRASH(input);
    
    int x;
    char ch;
    do{
        input>>x;
        input>>ch;
        chooses.push_back(x);
    }while(ch==',');
}

Fact::~Fact() {
}

const string& Fact::name(){
    return s;
}

