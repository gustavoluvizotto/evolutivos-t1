/* 
 * File:   WinServices.cpp
 * Author: marcio
 * 
 * Created on 13 de Dezembro de 2012, 01:14
 */

#include "WinServices.h"

WinServices::WinServices(Run *exec){
    services.push_back(exec);
}
WinServices::~WinServices() {
}
int WinServices::n_servs(){
    return services.size();
}
int WinServices::n_facts(){
    return factorys.size();
}
Node* WinServices::nextServ(){
    Node *r = services.front();
    services.erase(services.begin());
    return r;
}
const Factory* WinServices::nextFact(){
    const Factory *r = factorys.front();
    factorys.erase(factorys.begin());
    return r;
}
void WinServices::add(const Factory* factory) throw(exception){
    PRINTF_2("\tadd %s\n", factory->name());
    factorys.push_back(factory);
}

