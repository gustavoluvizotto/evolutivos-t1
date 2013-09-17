/* 
 * File:   pBoundDbl.h
 * Author: andre
 *
 * Created on 14 de Dezembro de 2012, 17:21
 */

#ifndef BOUNDINT_H
#define	BOUNDINT_H

#include "uException.h"
#include <cstdlib>
#include <string>

using std::string;

class BoundInt {
public:
    BoundInt(int lb, int ub);
    virtual ~BoundInt();
    
    virtual double valid(double value);
    int compareTo(double a, double b);
protected:
    int lb;
    int ub;    
private:

};
#endif	/* PBOUNDDBL_H */

