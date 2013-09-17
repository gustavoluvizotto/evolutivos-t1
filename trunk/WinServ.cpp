/* 
 * File:   WinServ.cpp
 * Author: marcio
 * 
 * Created on 13 de Dezembro de 2012, 01:14
 */

#include "WinServ.h"
#include "Node.h"
#include "NodeFactory.h"
#include "Factory.h"
#include "Set.h"
#include "dVertex.h"
#include "NodeEnd.h"
#include "LinkerNodes.h"

#include <string>
#include <fstream>
#include <exception>
#include <typeinfo>

using std::ofstream;
using std::endl;
using std::type_info;

WinServ::WinServ() : ID(0) , enable_need(false)
MEMBER
END

WinServ::~WinServ() 
MEMBER
END

int WinServ::newID() 
MEMBER
    RETURN ID++;
END

int WinServ::sizeF() 
MEMBER
    DEBUGF_2("sizeF(%d)\n", fifo_f.size());
    RETURN fifo_f.size();
END

int WinServ::sizeS() 
MEMBER
    DEBUGF_2("sizeS(%d)\n", fifo_s.size());
    RETURN fifo_s.size();
END


void WinServ::push_back(const Factory* f) 
MEMBER
    DEBUGF_2("push_back(%s)\n", f->name());
    fifo_f.push_back(f);
END

const Factory* WinServ::take_F() 
MEMBER
    DEBUGF_1("take_F\n");
    const Factory* f = fifo_f.front();
    fifo_f.erase(fifo_f.begin());
    DEBUGF_2("take_F(%s)\n", f->name());
    RETURN f;
END

Set* WinServ::take_S() 
MEMBER
    DEBUGF_1("take_S\n");
    Set* s = fifo_s.front();
    fifo_s.erase(fifo_s.begin());
    DEBUGF_2("take_S(%s)\n", s->name().c_str());
    RETURN s;
END

void WinServ::update() throw (exception) 
MEMBER
    PRINTF_1("---------- enable_needs ------------\n");
    enable_need = true;
    for (int v = 0; v < vertexes.size(); v++) {
        vertex = vertexes[v];
        set_activate = vertexes[v]->getSet();

        PRINTF_2("Begin Servicer[%d]\n", set_activate->serv()->getID());
        try {
            set_activate->serv()->services(ptr);
        } catch (exception& ex) {
            PRINTF_1("------------ exception ex ---------------\n");
            PRINTF_2("%s\n", ex.what());
        }
        set_activate = NULL;
        vertex = NULL;
        DEBUGF_1("End\n");
    }
    
    PRINTF_1("------------ update ---------------\n");
    for (int v = 0; v < vertexes.size(); v++) {
        vertexes[v]->update(vertexes);
    }
    
    //mark death nodes
    for (int v = 0; v < vertexes.size(); v++) {
        vertexes[v]->mark_death();
    }
    
    enable_need = false;
END

bool WinServ::Step2(Set* set) throw (exception) 
MEMBER
    int step2 = 0;
    DEBUGF_2("step2-%d\n", step2++);
    for (int s = 0; s < all.size(); s++) {
        if (all[s]->name() == set->name()) {
            PRINTF_4("Conflict of names [%s]\n\t%s\n\t%s\n",
                    all[s]->name().c_str(),
                    typeid (all[s]->serv()).name(),
                    typeid (set->serv()).name());
        }
    }
    DEBUGF_2("step2-%d\n", step2++);
    all.push_back(set);
    
    set_activate = set;
    vertex = new dVertex(set);
    vertexes.push_back(vertex);
    DEBUGF_2("step2-%d\n", step2++);
    
    PRINTF_4("[%d]:%s -> end-node = %s\n", set->getID(), set->name().c_str(), instanceof(set->serv(), NodeEnd*) ? "true" : "false");
    if (instanceof(set->serv(), NodeEnd*)) {
        set_activate = NULL;
        vertex = NULL;
        RETURN true;
    }
    DEBUGF_2("step2-%d\n", step2++);
    
    PRINTF_2("Begin Servicer[%d]\n", set->getID());
    
    
    try {
        DEBUGF_3("step2-%d - %d\n", step2++, ptr);
        set->serv()->services(ptr);
        DEBUGF_2("step2-%d\n", step2++);
    } catch (exception& ex) {
        PRINTF_1("------------ exception ex ---------------\n");
        PRINTF_2("%s\n", ex.what());
    }
    
    DEBUGF_2("step2-%d\n", step2++);
    
    set_activate = NULL;
    vertex = NULL;
    DEBUGF_1("End\n");
    
    RETURN false;
END

void WinServ::Step1(NodeFactory* node, const Factory* factory) throw (exception) 
MEMBER
    set_activate = new Set(node, factory);
    vertex = new dVertex(set_activate);

    vertexes.push_back(vertex);

    set_activate->serv()->services(ptr);

    set_activate = NULL;
    vertex = NULL;
END

void WinServ::savePof(const string& name) throw (exception) 
MEMBER
    ofstream output(name.c_str(), ofstream::out);
    for (int v = 0; v < vertexes.size(); v++) {
        salvePof(output, vertexes[v]);
    }
    output.close();
END

void WinServ::saveSgl(const string& name) throw (exception) 
MEMBER
    ofstream output(name.c_str(), ofstream::out);
    output << "<nodes number>" << endl;
    output << vertexes.size() << endl;
    for (int v = 0; v < vertexes.size(); v++) {
        salveSgl(output, vertexes[v]);
    }
    output.close();
END

bool WinServ::containsS(Node* serv) 
MEMBER
    for (int i = 0; i < fifo_s.size(); i++) {
        if (fifo_s[i]->getID() == serv->getID()) {
            RETURN true;
        }
    }
    RETURN false;
END

bool WinServ::containsF(const Factory* fact) 
MEMBER
    for (int i = 0; i < fifo_f.size(); i++) {
        if (fifo_f[i] == fact) {
            RETURN true;
        }
    }
    RETURN false;
END
            
            
void WinServ::add(const Factory* factory) throw (exception)
MEMBER
    if (!enable_need && factory != NULL) {
        if (containsF(factory)) {
            PRINTF_2("AddFactory %s\n", factory->name());
            vertex->add("null", factory);
        } else {
            PRINTF_2("AddFactory %s\n", factory->name());
            fifo_f.push_back(factory);
            vertex->add("null", factory);
        }
    }
END

