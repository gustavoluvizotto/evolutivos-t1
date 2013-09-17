/* 
 * File:   ACKOperator.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef ACKOPERATOR_H
#define	ACKOPERATOR_H

#include "Factory.h"

class ACKOperator : public Factory {
public:
    static const ACKOperator obj;
    ACKOperator();
    virtual ~ACKOperator();

    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* ACKOPERATOR_H */
