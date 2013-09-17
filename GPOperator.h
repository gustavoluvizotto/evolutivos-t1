/* 
 * File:   GPOperator.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef GPOPERATOR_H
#define	GPOPERATOR_H

#include "Factory.h"

class GPOperator : public Factory{
public:
    static const GPOperator obj;
    GPOperator();
    virtual ~GPOperator();
    
    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* GPOPERATOR_H */

