/* 
 * File:   SINU20Operator.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef SINU20OPERATOR_H
#define	SINU20OPERATOR_H

#include "Factory.h"

class SINU20Operator : public Factory {
public:
    static const SINU20Operator obj;
    SINU20Operator();
    virtual ~SINU20Operator();

    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* SINU20OPERATOR_H */
