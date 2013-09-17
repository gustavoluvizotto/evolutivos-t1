/* 
 * File:   fProblem.h
 * Author: marcio
 *
 * Created on 8 de Março de 2013, 22:28
 */

#ifndef FPROBLEM_H
#define	FPROBLEM_H

#include "Factory.h"

class Node;

class fProblem : public Factory{
public:
    static const fProblem obj;
    fProblem();
    virtual ~fProblem();
    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:

};
#endif	/* METAPROBLEMFACTORY_H */

