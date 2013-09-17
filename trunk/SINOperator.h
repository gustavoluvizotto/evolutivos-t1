/* 
 * File:   SINOperator.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef SINOPERATOR_H
#define	SINOPERATOR_H

#include "Factory.h"

class SINOperator : public Factory {
public:
    static const SINOperator obj;
    SINOperator();
    virtual ~SINOperator();

    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* SINOPERATOR_H */
