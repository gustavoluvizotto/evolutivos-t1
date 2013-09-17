/* 
 * File:   Node.cpp
 * Author: marcio
 * 
 * Created on 14 de Dezembro de 2012, 18:21
 */

#include "Node2.h"
#include "Node.h"

Node2::Node2(Node* s): serv(s) {
    nm = string(s->name());
}
Node2::~Node2() {

}

const string& Node2::name()const{
    return nm;
}

void Node2::add(Node* serv){
    this->facts.push_back(serv);
}
void Node2::add(vector<Node*>* list){
    this->needs.push_back(list);
}
/*template<class T>
void Node::addNeed(T* list){
    this->needs.push_back(dynamic_cast<vector<NodeService*>*>(list));
}
*/
/*
template<class T>
void Node::addNeed(vector<T*>* list){
    vector<NodeService*>* aux = new vector<NodeService*>();
    for(int i=0; i<list->size(); i++){
        T* no = (*list)[i];
        aux->push_back(dynamic_cast<NodeService*>(no));
    }
    this->needs.push_back(aux);
}*/
void Node2::set(vector<const string>* params){
    this->params = params;
}
Node* Node2::get_facts(int index){
    return facts[index];
}

