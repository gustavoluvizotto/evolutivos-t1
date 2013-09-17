/* 
 * File:   ComServices.h
 * Author: marcio
 *
 * Created on 13 de Março de 2013, 17:49
 */

#ifndef LINKERNODES_H
#define	LINKERNODES_H

#include <vector>
#include "WinServices.h"
#include "WinServ.h"
#include "WinNeeds.h"

using std::vector;

class LinkerNodes {
public:
    LinkerNodes(WinServices* winA, WinServ* winB, WinNeeds* winC);
    virtual ~LinkerNodes();
    
    void addf(const Factory* factory) throw (exception);
    
    
    template<class T> T* add(T* service) throw(exception);
    
    template<class T> T* get(const Factory* factory, T* type) throw(exception);
    
    template<class T> vector<T*>* gets(const Factory* factory, T* type) throw(exception);
    
    template<class T> T* need(T *type) throw(exception) ;
    
    template<class T> vector<T*>* needs(T* type) throw(exception);
private:
    WinServices* WinA;
    WinServ* WinB;
    WinNeeds* WinC;
};

template<class T>
T* LinkerNodes::add(T* service) throw(exception){
    if(service!=NULL){
        if(WinA!=NULL){
            return WinA->add(service);
        }else if(WinB!=NULL){
            return WinB->add(service);
        }else if(WinC!=NULL){
            return WinC->add(service);
        }else{
            THROW("dont have Win!=NULL");
        }
    }
}

template<class T> 
T* LinkerNodes::get(const Factory* factory, T* type) throw(exception){
    if(WinA!=NULL){
        return WinA->get(factory, type);
    }else if(WinB!=NULL){
        return WinB->get(factory, type);
    }else if(WinC!=NULL){
        return WinC->get(factory, type);
    }else{
        THROW("dont have Win!=NULL");
    }
}

template<class T> 
vector<T*>* LinkerNodes::gets(const Factory* factory, T* type) throw(exception){
    if(WinA!=NULL){
        return WinA->gets(factory, type);
    }else if(WinB!=NULL){
        return WinB->gets(factory, type);
    }else if(WinC!=NULL){
        return WinC->gets(factory, type);
    }else{
        THROW("dont have Win!=NULL");
    }
}

template<class T> 
T* LinkerNodes::need(T *type) throw(exception){
    if(WinA!=NULL){
        return WinA->need(type);
    }else if(WinB!=NULL){
        return WinB->need(type);
    }else if(WinC!=NULL){
        return WinC->need(type);
    }else{
        THROW("dont have Win!=NULL");
    }
}

template<class T> 
vector<T*>* LinkerNodes::needs(T* type) throw(exception){
    if(WinA!=NULL){
        return WinA->needs(type);
    }else if(WinB!=NULL){
        return WinB->needs(type);
    }else if(WinC!=NULL){
        return WinC->needs(type);
    }else{
        THROW("dont have Win!=NULL");
    }
}

#endif	/* COMSERVICES_H */

