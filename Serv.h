/* 
 * File:   Serv.h
 * Author: marcio
 *
 * Created on 14 de Dezembro de 2012, 20:01
 */

#ifndef SERV_H
#define	SERV_H

#include <iostream>
#include <string>
#include <vector>

using std::istream;
using std::string;
using std::vector;


class Serv {
    friend class WinParams;
public:
    Serv( istream& input );
    virtual ~Serv();
    const string& name()const;
private:
    string s;
    vector<string> params;
};

#endif	/* SERV_H */

