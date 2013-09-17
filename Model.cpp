/* 
 * File:   Model.cpp
 * Author: marcio
 * 
 * Created on 13 de Dezembro de 2012, 00:02
 */

#include "Model.h"
#include "dVertex.h"
#include "WinServ.h"
#include "Factory.h"
#include "fRun.h"
#include "NodeFactory.h"
#include "ComDefines.h"
#include "uException.h"
#include "ComDefines.h"
#include "Set.h"

#include <fstream>
#include <exception>

using std::ofstream;
using std::exception;
using std::endl;

Model::Model(){
    winServ = new LinkerNodes(NULL, &winB, NULL);
    winB.set_ptr(winServ);
}

Model::~Model() {
}

void Model::savePof(const string& name) throw (exception)
MEMBER
    winB.savePof(name);
END

void Model::saveSgl(const string& name) throw (exception)
MEMBER
    winB.saveSgl(name);
END

void Model::split(const Factory* factory) throw (exception)
MEMBER
    NodeFactory *node = new NodeFactory(factory);
    node->setID(winB.newID());
    
    int index = 0;
    Node* serv = factory->NewService(index);
    while (serv != NULL) {
        serv->construct();
        node->add(serv);
        index++;
        serv = factory->NewService(index);
        if (index > MAX_SERVICE_FACTORY) {
            throw uException("Infinit loop : index > MAX_SERVICE_FACTORY");
        }
    }
    winB.Step1(node, factory);
END

void Model::create(const fRun* obj) throw (exception)
MEMBER
    //dVertex vertex = new dVertex(null);
    //vertex.add(obj);
    //vertexes.addLast(vertex);

    winB.push_back(obj);

    while (winB.sizeF() > 0) {
        const Factory* fact = winB.take_F();
        split(fact);
        if (winB.sizeS() == 0) {
            continue;
        }
        PRINTF_1("Begin Implementations\n");

        while (winB.sizeS() > 0) {
            Set* set = winB.take_S();
            if (winB.Step2(set)) {
                continue;
            }
        }
        PRINTF_1("End\n");
    }

    DEBUGF_1("Aqui-1!\n");
    winB.update();

    DEBUGF_1("Aqui-2!\n");
END

