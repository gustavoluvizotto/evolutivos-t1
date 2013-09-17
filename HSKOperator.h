/* 
 * File:   HSKOperator.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef HSKOPERATOR_H
#define	HSKOPERATOR_H

#include "Factory.h"

class HSKOperator : public Factory{
public:
    static const HSKOperator obj;
    HSKOperator();
    virtual ~HSKOperator();
    
    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* HSKOPERATOR_H */

