/* 
 * File:   KLOperator.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef KLOPERATOR_H
#define	KLOPERATOR_H

#include "Factory.h"

class KLOperator : public Factory {
public:
    static const KLOperator obj;
    KLOperator();
    virtual ~KLOperator();

    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* KLOPERATOR_H */

