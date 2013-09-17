/* 
 * File:   BROperator.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef BROPERATOR_H
#define	BROPERATOR_H

#include "Factory.h"

class BROperator : public Factory {
public:
    static const BROperator obj;
    BROperator();
    virtual ~BROperator();

    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* BROPERATOR_H */
