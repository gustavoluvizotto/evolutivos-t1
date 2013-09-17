/* 
 * File:   Node.h
 * Author: marcio
 *
 * Created on 14 de Dezembro de 2012, 18:21
 */

#ifndef NODE2_H
#define	NODE2_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class Node;

class Node2 {
    friend class Runner;
public:
    Node2(Node* s);
    virtual ~Node2();
    
    const string& name()const; 
    
    void add(Node* serv);
    
    void add(vector<Node*>* list);
    
    void set(vector<const string>* params);
    Node* get_facts(int index);
    
    Node* Serv(){
        return serv;
    }
private:
    string nm;
    Node *serv;
    vector<const string> *params;
    vector<Node*> facts;
    
    vector<vector<Node*>*> needs;
};

#endif	/* NODE_H */

