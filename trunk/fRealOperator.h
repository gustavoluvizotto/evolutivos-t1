/* 
 * File:   fRealOperator.h
 * Author: marcio
 *
 * Created on 11 de Junho de 2013, 18:27
 */

#ifndef FREALOPERATOR_H
#define	FREALOPERATOR_H

#include "Factory.h"

class fRealOperator : public Factory {
public:
    static const fRealOperator obj;
    fRealOperator();
    virtual ~fRealOperator();
    virtual const char* name()const;
    virtual Node* NewService(int index)const;
};

#endif	/* FREALOPERATOR_H */

