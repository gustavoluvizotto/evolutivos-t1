/* 
 * File:   aRealMultiObj.h
 * Author: marcio
 *
 * Created on 17 de Junho de 2013, 17:53
 */

#ifndef AREALMULTIOBJ_H
#define	AREALMULTIOBJ_H

#include "BoundDbl.h"
#include "iFunction.h"

class aRealMultiObj {
public:
    aRealMultiObj(){};
    virtual ~aRealMultiObj(){};
    virtual const char* name() const = 0;
    virtual int size() const = 0;
    virtual int goals() const = 0;
    virtual iFunction** New() const = 0;
    double F(int i, double* X, int length) const{
        return objs[i]->F(X, length);
    }
    void construct(){
        objs = New();
    }
    virtual const BoundDbl** bounds() const{
        int g = goals();
        const BoundDbl** bounds = new const BoundDbl*[g];
        for(int i=0; i<g; i++){
            bounds[i] = &BoundDbl::def;
        }
        return bounds;
    }
    static double decode(double x, double min, double max){
        return min + x*(max-min);
    }
private:
    iFunction** objs;
};

#endif	/* AREALMULTIOBJ_H */

