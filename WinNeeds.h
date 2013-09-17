/* 
 * File:   WinNeeds.h
 * Author: marcio
 *
 * Created on 14 de Dezembro de 2012, 20:42
 */

#ifndef WINNEEDS_H
#define	WINNEEDS_H

#include <vector>
#include <string>
#include <iomanip>

#include "Node2.h"
#include "Factory.h"
#include "uException.h"
#include "ComDefines.h"
#include "Node.h"

class LinkerNodes;

using std::vector;
using std::setw;

class WinNeeds {
public:
    WinNeeds(vector<Node2*>* all);
    virtual ~WinNeeds();
    
    void start(Node2* activate);
    void set_ptr(LinkerNodes *p);
    void add(const Factory *factory) throw (exception);
    
    template<class T> T* add(T* service) throw(exception);
    template<class T> T* get(const Factory* factory, T* type) throw(exception);
    template<class T> vector<T*>* gets(const Factory* factory, T* type) throw(exception);
    template<class T> T* need(T *type) throw(exception) ;
    template<class T> vector<T*>* needs(T* type) throw(exception);
    
private:
    LinkerNodes *ptr;
    int g;
    Node2* node_activate;
    vector<Node2*>* all_nodes;
    
    template<class T> void make_need(T *type, char signal) throw(exception);
    
    template<class T> T* return_need(T *type) throw(exception);
    
    template<class T> vector<T*>* return_needs(T *type) throw(exception);
};

template<class T>
T* WinNeeds::add(T* service) throw(exception) {
    return service;
}
template<class T>
T* WinNeeds::get(const Factory* factory, T* type) throw(exception){
    return (T*)(node_activate->get_facts(g++));
}

template<class T>
vector<T*>* WinNeeds::gets(const Factory* factory, T* type) throw(exception){
    return NULL;
}


template<class T>
T* WinNeeds::need(T *type) throw(exception) {
    return return_need(type);
}
template<class T>
vector<T*>* WinNeeds::needs(T* type) throw(exception) {
    return return_needs(type);
}

template<class T>
T* WinNeeds::return_need(T *type) throw(exception) {
    vector<Node*>* L = new vector<Node*>();
    vector<T*>* R = new vector<T*>();
    for(int i=0; i<all_nodes->size(); i++){
        Node2* no = (*all_nodes)[i];
        T* p;
        if(p = dynamic_cast<T*>(no->Serv())){
            L->push_back(p);
            R->push_back(p);
        }     
    }
    if(L->size()!=1){
        ostringstream s;
        s << "Conflict list of need size()!=1 to type = '" << typeid(T).name() << "'";
        throw uException(s.str());
    }
    node_activate->add(L);
    return R->front();
}

template<class T>
vector<T*>* WinNeeds::return_needs(T *type) throw(exception) {
    vector<Node*>* L = new vector<Node*>();
    vector<T*>* R = new vector<T*>();
    for(int i=0; i<all_nodes->size(); i++){
        Node2* no = (*all_nodes)[i];
        T* p;
        if(p = dynamic_cast<T*>(no->Serv())){
            L->push_back(p);
            R->push_back(p);
        }
    }
    if(L->size()<=0){
        ostringstream s;
        s << "Not find list of needs for '" << typeid(T).name() << "', all nodes below" <<endl;
        for(int i=0; i<all_nodes->size(); i++){
            Node2* no = (*all_nodes)[i];
            s << "\t\t[ "<<setw(5) << no->Serv()->getID() <<" - " <<setw(12) << no->name() << endl;
        }
        throw uException(s.str());
    }
    node_activate->add(L);
    return R;
}


#endif	/* WINNEEDS_H */

