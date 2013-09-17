/* 
 * File:   iFunction.h
 * Author: marcio
 *
 * Created on 17 de Junho de 2013, 17:48
 */

#ifndef IFUNCTION_H
#define	IFUNCTION_H

class iFunction {
public:
    iFunction(){}
    virtual ~iFunction(){}
    virtual double F(double* X, int length) const = 0;
private:

};

#endif	/* IFUNCTION_H */

