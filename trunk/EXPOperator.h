/* 
 * File:   EXPOperator.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef EXPOPERATOR_H
#define	EXPOPERATOR_H

#include "Factory.h"

class EXPOperator : public Factory{
public:
    static const EXPOperator obj;
    EXPOperator();
    virtual ~EXPOperator();
    
    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* EXPOPERATOR_H */

