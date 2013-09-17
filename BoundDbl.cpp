/* 
 * File:   pBoundDbl.cpp
 * Author: andre
 * 
 * Created on 14 de Dezembro de 2012, 17:21
 */

#include "BoundDbl.h"

#include <sstream>
#include <iomanip>
#include <typeinfo>
#include <stdio.h>
#include <math.h>


using std::type_info;
using std::stringstream;
using std::setw;

const BoundDbl BoundDbl::def(-1e6, 1e6, 1e-6, "value", 12);

BoundDbl::BoundDbl(double lb, double ub, double precision, const char* name, int col) {    
    if(lb>=ub){
        stringstream message;
        message << "constructor " << typeid(this).name()
                << " --> lb>=ub --> " << lb << ">=" << ub;        
        throw new uException(string(message.str()));
    }
    this->lb = lb;
    this->ub = ub;
    this->precision = precision;
    this->name = name;
    this->col = col;
}
/*pBoundDbl::pBoundDbl() {
    this->lb = 0;
    this->ub = 1e6;
    this->precision = 1e-6;
    this->name = "value";
    this->col = 12;
}*/

BoundDbl::~BoundDbl() {
}

double BoundDbl::valid(double value) const{
    if(value>ub){
        //uWarnning.format("value > ub -> %g > %g\n", value, ub);
        return ub;
    }else if(value<lb){
        //uWarnning.format("value < lb -> %g < %g\n", value, lb);
        return lb;
    }else{
        return value;
    }
}
double BoundDbl::relative(double value) const{
    return (value-lb)/(ub-lb);
}
bool BoundDbl::EQ(double a, double b) const{
    return fabs(b-a) < precision;
}
bool BoundDbl::GT(double a, double b) const{
    return a - precision > b;
}
bool BoundDbl::LT(double a, double b) const{
    return a + precision < b;
}
int BoundDbl::compareTo(double a, double b) const{
    if(LT(a,b)){
        return -1;        
    } else if(GT(a,b)){
        return 1;
    } else {
        return 0;
    }
}
void BoundDbl::PrintTitle(ostream &out)const{
    out << setw(col) << this->name;
}
void BoundDbl::PrintValue(ostream &out, double value)const{
    out << setw(col) << value;
}

