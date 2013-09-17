/* 
 * File:   NodeFactory.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 21:34
 */

#ifndef NODEFACTORY_H
#define	NODEFACTORY_H

#include <string>
#include <exception>

#include "uException.h"
#include "Node.h"
#include "Factory.h"
#include "LinkerNodes.h"

using std::string;
using std::exception;

class NodeFactory : public Node {
public:
    NodeFactory(const Factory* f):factory(f){
        
    }
    virtual ~NodeFactory(){}
    
    void add(Node *serv){
        list.push_back(serv);
    }
    
    const char* name() const{
        return factory->name();
    }
    const char* description() const{
        throw uException("Not supported yet.");
        //return factory.name();
    }

    void services(LinkerNodes *com) throw(exception){
        for(int i=0; i<list.size(); i++){
            com->add(list[i]);
        }
    }
    void parameters(LinkerParameters *com) throw(exception){
        
    }
    bool validation(LinkerValidations *com) throw(exception){
        throw uException("Not supported yet.");
    }
    void load() throw(exception) {
        throw uException("Not supported yet.");
    }
    void start() throw(exception) {
        throw uException("Not supported yet.");
    }
    void results(LinkerResults *com) throw(exception){
        throw uException("Not supported yet.");
    }
private:
    const Factory* factory;
    vector<Node*> list;
};

#endif	/* NODEFACTORY_H */

