/* 
 * File:   LM2Operator.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef LM2OPERATOR_H
#define	LM2OPERATOR_H

#include "Factory.h"

class LM2Operator : public Factory{
public:
    static const LM2Operator obj;
    LM2Operator();
    virtual ~LM2Operator();
    
    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* LM2OPERATOR_H */

