/* 
 * File:   iStopTime.cpp
 * Author: marcio
 * 
 * Created on 10 de Abril de 2013, 14:46
 */

#include "iStopTime.h"
#include "LinkerParameters.h"
#include <time.h>

iStopTime::iStopTime() {
    
}
iStopTime::~iStopTime() {
    
}
const char* iStopTime::name() const{
    return "Time";
}
const char* iStopTime::description() const{
    return "not yet";
}
void iStopTime::parameters(LinkerParameters *com) throw(exception) {
    time = com->Dbl("Time", 60, 1e-3, 1e6, "the time of execution (seconds)");
}
void iStopTime::start() throw(exception){
    initial_time = static_cast<double>(clock());
}
double iStopTime::progress() throw(exception){
    return (static_cast<double>(clock())-initial_time)/(CLOCKS_PER_SEC*time);
}
bool iStopTime::end() throw(exception){
    double p = progress();
    return p>1.0;
}

