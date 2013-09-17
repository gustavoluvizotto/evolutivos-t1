/* 
 * File:   ExecutablesFactory.h
 * Author: marcio
 *
 * Created on 15 de Março de 2013, 01:56
 */

#ifndef FRUN_H
#define	FRUN_H

#include "Factory.h"

class Node;

class fRun : public Factory{
public:
    static const fRun obj;
    fRun(){}
    virtual ~fRun(){}
    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:

};

#endif	/* EXECUTABLESFACTORY_H */

