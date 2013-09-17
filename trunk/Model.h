/* 
 * File:   Model.h
 * Author: marcio
 *
 * Created on 13 de Dezembro de 2012, 00:02
 */

#ifndef MODEL_H
#define	MODEL_H

#include <exception>

#include "WinServ.h"
#include "LinkerNodes.h"

using std::exception;

class Factory;
class fRun;

class Model {
public:
    Model();
    virtual ~Model();
    void savePof(const string& name) throw(exception);
    void saveSgl(const string& name) throw(exception);
    void create(const fRun* obj) throw(exception);
    
private:
    LinkerNodes* winServ;
    WinServ winB;
    
    void split(const Factory* factory) throw(exception);
};

#endif	/* MODEL_H */

