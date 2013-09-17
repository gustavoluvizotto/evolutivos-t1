/* 
 * File:   CMOperator.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef CMOPERATOR_H
#define	CMOPERATOR_H

#include "Factory.h"

class CMOperator : public Factory{
public:
    static const CMOperator obj;
    CMOperator();
    virtual ~CMOperator();
    
    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* CMOPERATOR_H */

