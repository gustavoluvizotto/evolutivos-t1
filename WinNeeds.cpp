/* 
 * File:   WinNeeds.cpp
 * Author: marcio
 * 
 * Created on 13 de Dezembro de 2012, 01:14
 */

#include "WinNeeds.h"

WinNeeds::WinNeeds(vector<Node2*>* all)
    :  all_nodes(all){
}
WinNeeds::~WinNeeds() {
}
void WinNeeds::start(Node2* activate){
    this->node_activate = activate;
    this->g = 0;
}
void WinNeeds::set_ptr(LinkerNodes *p){
    ptr = p;
}
void WinNeeds::add(const Factory* factory) throw(exception) {

};


