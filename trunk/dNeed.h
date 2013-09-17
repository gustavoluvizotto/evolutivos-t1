/* 
 * File:   dNeed.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 22:39
 */

#ifndef DNEED_H
#define	DNEED_H

#include <vector>
#include <iostream>

#include "uException.h"

class dVertex;

using std::vector;

class dNeed {
public:
    dNeed(char signal, const char* type) : s(signal), t(type) {};
    
    virtual ~dNeed(){};
    
    void addVertex(dVertex* vertex) 
    MEMBER
        vertexes.push_back(vertex);
    END
    int size() const
    MEMBER
        RETURN vertexes.size();
    END
    char signal() const
    MEMBER
        RETURN s;
    END
    const char* type() const
    MEMBER
        RETURN t;
    END
    const vector<dVertex*>& get() const
    MEMBER
        RETURN vertexes;
    END
private:
    char s;
    const char* t;
    vector<dVertex*> vertexes;
};

#endif	/* DNEED_H */

