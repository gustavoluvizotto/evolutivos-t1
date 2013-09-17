/* 
 * File:   HVOperator.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef HVOPERATOR_H
#define	HVOPERATOR_H

#include "Factory.h"

class HVOperator : public Factory{
public:
    static const HVOperator obj;
    HVOperator();
    virtual ~HVOperator();
    
    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* HVOPERATOR_H */

