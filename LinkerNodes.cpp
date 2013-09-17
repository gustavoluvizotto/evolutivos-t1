/* 
 * File:   ComServices.cpp
 * Author: marcio
 * 
 * Created on 13 de Dezembro de 2012, 01:14
 */

#include "LinkerNodes.h"

LinkerNodes::LinkerNodes(WinServices* winA, WinServ* winB, WinNeeds* winC)
    : WinA(winA), WinB(winB), WinC(winC){

}

LinkerNodes::~LinkerNodes(){

}


void LinkerNodes::addf(const Factory* factory) throw (exception){
    if(factory!=NULL){
        if(WinA!=NULL){
            WinA->add(factory);
        }else if(WinB!=NULL){
            WinB->add(factory);
        }else if(WinC!=NULL){
            WinC->add(factory);
        }else{
            THROW("dont have Win!=NULL");
        }
    }
}

