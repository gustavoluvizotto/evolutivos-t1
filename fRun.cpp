/* 
 * File:   ExecutablesFactory.cpp
 * Author: marcio
 * 
 * Created on 15 de Março de 2013, 01:56
 */

#include "fRun.h"
#include "GeneticAlgorithm.h"

const fRun fRun::obj;

const char* fRun::name()const{
    return "Run";
}
Node* fRun::NewService(int index)const{
    switch(index){
        case 0 : return new GeneticAlgorithm();
    }
    return NULL;
}

