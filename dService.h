/* 
 * File:   dService.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 22:46
 */

#ifndef DSERVICE_H
#define	DSERVICE_H

#include <vector>
#include <exception>

#include "uException.h"
#include "ComDefines.h"
#include "dVertex.h"
#include "Node.h"

using std::vector;

template<class V>
class dService {
public:
    dService(Node* s) : serv(s) {};
    
    virtual ~dService(){}
    
    void addVertex(V* vertex) throw(exception)
    MEMBER
        DEBUGF_2("addVertex = %d\n", vertex->getID());
        if(vertexes.size()>0){
            throw uException("in dService: vertexes.size>0");
        }
        vertexes.push_back(vertex);
    END
    int size() const
    MEMBER
        RETURN vertexes.size();
    END
    int getID()
    MEMBER
        RETURN serv->getID();
    END
private:
    Node* serv;
    vector<V*> vertexes;
};

#endif	/* DSERVICE_H */

