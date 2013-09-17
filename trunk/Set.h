/* 
 * File:   Set.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 22:16
 */

#ifndef SET_H
#define	SET_H

#include <vector>
#include <string>

class Node;
class Factory;
class SaveSgl;

using std::vector;
using std::string;

class Set {
public:
    Set(Node* serv, const Factory* fact);
    virtual ~Set();
    int getID() const;
    const vector<int>& get_dads() const;
    const string& name() const;
    bool operator==(const Set &obj) const;
    Node* serv() const;
    const Factory* fact() const;
    void parameters(SaveSgl *com);
private:
    string nm;
    Node* s;
    const Factory* f;
};

#endif	/* SET_H */

