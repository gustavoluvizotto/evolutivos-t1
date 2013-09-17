/* 
 * File:   WinServices.h
 * Author: marcio
 *
 * Created on 14 de Dezembro de 2012, 17:13
 */

#ifndef WINSERVICES_H
#define	WINSERVICES_H

#include <vector>


#include "Run.h"
#include "Factory.h"
#include "ComDefines.h"

class LinkerNodes;

using std::vector;

class WinServices{
public:
    WinServices(Run *exec);
    virtual ~WinServices();
    
    int n_servs();
    int n_facts();
    Node* nextServ();
    const Factory* nextFact();
    
    void add(const Factory *factory) throw (exception);
    
    template<class T> T* add(T* service) throw(exception);
    template<class T> T* get(const Factory* factory, T* type) throw(exception);
    template<class T> vector<T*>* gets(const Factory* factory, T* type) throw(exception);
    template<class T> T* need(T *type) throw(exception) ;
    template<class T> vector<T*>* needs(T* type) throw(exception);
    
    void set_ptr(LinkerNodes *p){
        ptr = p;
    }
private:
    LinkerNodes *ptr;
    vector<const Factory*> factorys;
    vector<Node*> services;
};

template<class T> 
T* WinServices::add(T* service) throw(exception){
    if(service!=NULL){
        PRINTF_2("\tadd %s\n", service->name());
        services.push_back(service);
    }
    return service;
}

template<class T> 
T* WinServices::get(const Factory* factory, T* type) throw(exception){
    PRINTF_2("\tget %s\n", factory->name());
    factorys.push_back(factory);
    return NULL;
}
template<class T> 
vector<T*>* WinServices::gets(const Factory* factory, T* type) throw(exception){
    PRINTF_2("\tgets %s\n", factory->name());
    factorys.push_back(factory);
    return NULL;
}

template<class T>
T* WinServices::need(T *type) throw(exception){
    return NULL;
}
template<class T>
vector<T*>* WinServices::needs(T* type) throw(exception){
    return NULL;
}

#endif	/* WINSERVICES_H */

