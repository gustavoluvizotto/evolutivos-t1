/* 
 * File:   pBoundDbl.cpp
 * Author: andre
 * 
 * Created on 14 de Dezembro de 2012, 17:21
 */

#include "BoundInt.h"

#include <sstream>
#include <iomanip>
#include <typeinfo>

using std::type_info;
using std::stringstream;
using std::setw;
BoundInt::BoundInt(int lb, int ub) {    
    if(lb>=ub){
        stringstream message;
        message << "constructor " << typeid(this).name()
                << " --> lb>=ub --> " << lb << ">=" << ub;        
        throw new uException(string(message.str()));
    }
    this->lb = lb;
    this->ub = ub;    
}

BoundInt::~BoundInt() {
}

double BoundInt::valid(double value) {
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
int BoundInt::compareTo(double a, double b){
    if(a < b){
        return -1;        
    } else if(a > b){
        return 1;
    } else return 0;
}

