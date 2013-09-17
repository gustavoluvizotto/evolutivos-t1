/* 
 * File:   dVertex.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 22:41
 */

#ifndef DVERTEX_H
#define	DVERTEX_H

#include <vector>
#include <iostream>

#include "dService.h"
#include "dFactory.h"
#include "dNeed.h"

class Node;
class Factory;
//class Set;
#include "Set.h"
using std::vector;
using std::ostream;

class dVertex {
    friend void salvePof(ostream& output, dVertex *V) throw (exception);
    friend void salveSgl(ostream& output, dVertex *V) throw (exception);
public:
    dVertex(const Set* s) : set(s), death(false) {};
    virtual ~dVertex() {};
    
    bool operator==(const dVertex &obj) const;
    void add(Node* serv);
    void add(const char* type, const Factory* fact);
    void get(char signal, const char* type, const Factory* fact);
    
    void addNeeds(dNeed* need);
    const Set* getSet() const{
        return set;
    }
    int getID()const;
    void update(const vector<dVertex*> &vertexes) throw (exception);
    void mark_death();
private:
    const Set* set;
    bool death;
    vector<dService<dVertex>*> services;
    vector<dFactory<dVertex>*> factorys;
    vector<dNeed*> needs;
    Node** needs_type;
};

void salvePof(ostream& output, dVertex *V) throw (exception);
void salveSgl(ostream& output, dVertex *V) throw (exception);

#endif	/* DVERTEX_H */

