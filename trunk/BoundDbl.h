/* 
 * File:   pBoundDbl.h
 * Author: andre
 *
 * Created on 14 de Dezembro de 2012, 17:21
 */

#ifndef BOUNDDBL_H
#define	BOUNDDBL_H

#include "uException.h"
#include <cstdlib>
#include <string>
#include <ostream>
#include <cmath>

using std::string;
using std::ostream;

class BoundDbl {
public:
    static const BoundDbl def;
    
    BoundDbl(double lb, double ub, double precision, const char* name, int col);
    //pBoundDbl();
    virtual ~BoundDbl();
    
    virtual double valid(double value) const;
    double relative(double value) const;
    bool EQ(double a, double  b) const;
    bool GT(double a, double  b) const;
    bool LT(double a, double  b) const;
    int compareTo(double a, double b) const;

    void PrintTitle(ostream &out) const;
    void PrintValue(ostream &out, double value) const;
    
    double LB() const{
        return lb;
    }
    double UB() const{
        return ub;
    }
protected:
    BoundDbl(){
        BoundDbl(-1e6, 1e6, 1e-6, "value", 12);
    }
    
    double lb;
    double ub;
    double precision;
    const char* name;
    int col;
private:
    
};

#endif	/* PBOUNDDBL_H */

