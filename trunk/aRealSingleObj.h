/* 
 * File:   aRealSingleObj.h
 * Author: marcio
 *
 * Created on 17 de Junho de 2013, 17:49
 */

#ifndef AREALSINGLEOBJ_H
#define	AREALSINGLEOBJ_H

#include "iFunction.h"

class aRealSingleObj : public iFunction{
public:
    aRealSingleObj(){};
    virtual ~aRealSingleObj(){};
    virtual const char* name() const = 0;
    virtual int size() const = 0;
    virtual double F(double* X, int length) const = 0;
    static double decode(double x, double min, double max){
        return min + x*(max-min);
    }
};

#endif	/* AREALSINGLEOBJ_H */

