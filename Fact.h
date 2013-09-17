/* 
 * File:   Fact.h
 * Author: marcio
 *
 * Created on 14 de Dezembro de 2012, 20:32
 */

#ifndef FACT_H
#define	FACT_H

#include <iostream>
#include <string>
#include <vector>

using std::istream;
using std::string;
using std::vector;

class Runner;

class Fact {
    friend class Runner;
public:
    Fact(istream& input );
    virtual ~Fact();
    const string& name();
    
private:
    string s;
    vector<int> chooses;
};

#endif	/* FACT_H */

