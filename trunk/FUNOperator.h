/* 
 * File:   FUNOperator.h
 * Author: marcio
 *
 * Created on 29 de Agosto de 2013, 17:02
 */

#ifndef FUNOPERATOR_H
#define	FUNOPERATOR_H

#include "Factory.h"

class FUNOperator : public Factory {
public:
    static const FUNOperator obj;
    FUNOperator();
    virtual ~FUNOperator();
    
    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* FUNOPERATOR_H */

