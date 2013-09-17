/* 
 * File:   GRPOperator.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef GRPOPERATOR_H
#define	GRPOPERATOR_H

#include "Factory.h"

class GRPOperator : public Factory{
public:
    static const GRPOperator obj;
    GRPOperator();
    virtual ~GRPOperator();
    
    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* GRPOPERATOR_H */

