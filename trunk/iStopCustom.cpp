/* 
 * File:   iStopCustom.cpp
 * Author: marcio
 * 
 * Created on 28 de Agosto de 2013, 22:03
 */

#include "iStopCustom.h"
#include "LinkerParameters.h"

const iStopCustom iStopCustom::obj;

iStopCustom::iStopCustom() {
    
}
iStopCustom::~iStopCustom() {
    
}
const char* iStopCustom::name() const{
    return "Time";
}
const char* iStopCustom::description() const{
    return "not yet";
}
void iStopCustom::parameters(LinkerParameters *com) throw(exception) {
    
}
void iStopCustom::start() throw(exception){
    
}
double iStopCustom::progress() throw(exception){
    return 0.0;
}
bool iStopCustom::end() throw(exception){
    return false;
}

