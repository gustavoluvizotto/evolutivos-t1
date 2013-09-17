/* 
 * File:   WinServ.h
 * Author: marcio
 *
 * Created on 13 de Dezembro de 2012, 01:14
 */

#ifndef WINSERV_H
#define	WINSERV_H

#include <string>
#include <fstream>
#include <exception>
#include <typeinfo>

#include "ComDefines.h"
#include "Set.h"
#include "dVertex.h"
#include "Factory.h"


class NodeFactory;
class Node;
class LinkerNodes;

using std::type_info;
using std::exception;
using std::string;

class WinServ {
public:
    WinServ();
    virtual ~WinServ();
    
    int newID();
    void Step1(NodeFactory* node, const Factory* factory) throw(exception);
    bool Step2(Set* set) throw(exception);
    
    /*
    void add(NodeService* service) throw(exception);
    void add(FactoryService* factory) throw(exception);
    NodeService* get(FactoryService* factory) throw(exception);
    vector<NodeService>* gets(FactoryService* factory) throw(exception);
    */
    
    void add(const Factory* factory) throw (exception);
    
    template<class T> T* add(T* service) throw(exception);
    template<class T> T* get(const Factory* factory, T* type) throw(exception);
    template<class T> vector<T*>* gets(const Factory* factory, T* type) throw(exception);
    template<class T> T* need(T *type) throw(exception) ;
    template<class T> vector<T*>* needs(T* type) throw(exception);
    
    void savePof(const string& name) throw(exception);
    void saveSgl(const string& name) throw(exception);
    
    void push_back(const Factory* f);
    const Factory* take_F();
    Set* take_S();
    int sizeF();
    int sizeS();
    
    void update() throw(exception);
    
    void set_ptr(LinkerNodes *p){
        ptr = p;
    }
private:
    LinkerNodes *ptr;
    int ID;
    
    dVertex* vertex;
    vector<dVertex*> vertexes;
    bool enable_need;
    const Set* set_activate;
    
    vector<const Factory*> fifo_f;
    vector<Set*> fifo_s;
    vector<Set*> all;
    
    bool containsS(Node* serv);
    bool containsF(const Factory* fact);
    
    template<class T> void make_need(T *type, char signal) throw(exception);
    

    dVertex* find( const int &ID ){
        for(int i=0; i<vertexes.size(); i++){
            if(vertexes[i]->getID() == ID){
                return vertexes[i];
            }
        }
        return NULL;
    }
    
};

template<class T> 
T* WinServ::add(T* service) throw(exception)
MEMBER
    if (!enable_need && service != NULL) {
        service->add_dad(set_activate->getID());
        if (containsS(service)) {
            PRINTF_3("AddService %s(%d)\n", service->name(), service->getID());
            vertex->add(service);
        } else {
            service->setID(ID++);
            PRINTF_3("AddService %s(%d)\n", service->name(), service->getID());
            fifo_s.push_back(new Set(service, NULL));
            vertex->add(service);
        }
    }
    RETURN service;
END

template<class T> 
T* WinServ::get(const Factory* factory, T* type) throw(exception)
MEMBER
    if (!enable_need && factory != NULL) {
        if (containsF(factory)) {
            PRINTF_2("AddFactory %s\n", factory->name());
            vertex->get('1', typeid(type).name(), factory);//type_info(type).name()
        } else {
            PRINTF_2("AddFactory %s\n", factory->name());
            fifo_f.push_back(factory);
            vertex->get('1', typeid(type).name(), factory);//type_info(type).name()
        }
    }
    RETURN NULL;
END
    

template<class T> 
vector<T*>* WinServ::gets(const Factory* factory, T* type) throw(exception)
MEMBER
    if (!enable_need && factory != NULL) {
        if (containsF(factory)) {
            PRINTF_2("AddFactory %s\n", factory->name());
            vertex->get('+', typeid(type).name(), factory);
        } else {
            PRINTF_2("AddFactory %s\n", factory->name());
            fifo_f.push_back(factory);
            vertex->get('+', typeid(type).name(), factory);
        }
    }
    RETURN NULL;
END
            
template<class T>
T* WinServ::need(T *type) throw(exception){
    make_need(type, '1');
    return NULL;
}
template<class T>
vector<T*>* WinServ::needs(T* type) throw(exception){
    make_need(type, '+');
    return NULL;
}



template<class T>
void WinServ::make_need(T *type, char signal) throw(exception) {
    if (enable_need) {
        PRINTF_3("Need[%c] %s\n", signal ,typeid(type).name());

        if(set_activate==NULL){
            throw uException("activate = NULL");
        }
        dVertex* active = find(set_activate->getID());
        if(active==NULL){ 
            throw uException("find active = NULL; id = "+set_activate->getID());
        }

        dNeed* need = new dNeed(signal, typeid(type).name());

        for(int v = 0; v < vertexes.size(); v++){
            Node* serv = vertexes[v]->getSet()->serv();
            if(dynamic_cast<T*>(serv)){
                need->addVertex(vertexes[v]);
            }
        }

        active->addNeeds(need);
    }
}

#endif	/* WINSERV_H */

