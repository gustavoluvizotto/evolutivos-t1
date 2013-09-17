/* 
 * File:   NodeService.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 17:01
 */

#ifndef NODE_H
#define	NODE_H

#include <string>
#include <vector>
#include <exception>

#include "uException.h"

using std::string;
using std::vector;
using std::exception;

class LinkerNodes;
class LinkerParameters;
class LinkerValidations;
class LinkerResults;

class Node {
public:
    Node():ID(-1){
        
    }
    virtual ~Node(){}
    
    int getID() const
    MEMBER
        RETURN ID;
    END
    void setID(int ID) {
        this->ID = ID;
    }
    
    virtual const char* name() const = 0 ;
    virtual const char* description() const = 0;

    virtual void construct() throw(exception){
        
    }
    
    
    virtual void services(LinkerNodes *com) throw(exception) = 0;
    virtual void parameters(LinkerParameters *com) throw(exception) = 0;
    virtual bool validation(LinkerValidations *com) throw(exception) = 0;
    virtual void load() throw(exception) = 0;
    virtual void start() throw(exception) = 0;
    virtual void results(LinkerResults *com) throw(exception) = 0;
    
    const char* ref(){
        return name();
    }
    
    void add_dad(int index) {
        dads.push_back(index);
    }
    const vector<int>& get_dads() const {
        return dads;
    }
private:
    int ID;
    vector<int> dads;
};

#endif	/* NODESERVICE_H */

