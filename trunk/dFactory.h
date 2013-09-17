/* 
 * File:   dFactory.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 22:31
 */

#ifndef DFACTORY_H
#define	DFACTORY_H

#include <vector>
#include <exception>

#include "uException.h"
#include "Factory.h"

class Factory;

using std::vector;

template<class V>
class dFactory {
public:
    dFactory(char signal, const char* type, const Factory* f) : s(signal), t(type), factory(f) {};
    
    virtual ~dFactory(){}
    
    void addVertex(V* vertex) 
    MEMBER
        if(vertexes.size()>0){
            throw uException("in dFactory: vertexes.size>0");
        }
        vertexes.push_back(vertex);
    END
    
    bool operator==(const dFactory &obj) const
    MEMBER
        RETURN this->s==obj.s && this->factory == obj.factory;
    END
    char signal()
    MEMBER
        RETURN s;
    END
    const char* type()
    MEMBER
        RETURN t;
    END
    const char* name()
    MEMBER
        RETURN factory->name();
    END
    int size()
    MEMBER
        RETURN vertexes.size();
    END
    int getID()
    MEMBER
        RETURN vertexes.front()->getID();
    END
    const Factory* fact() const
    MEMBER
        RETURN factory;
    END
private:
    char s;
    const char* t;
    const Factory *factory;
    vector<V*> vertexes;
};

#endif	/* DFACTORY_H */

