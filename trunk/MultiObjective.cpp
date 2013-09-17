/* 
 * File:   pMultiObjective.cpp
 * Author: marcio
 * 
 * Created on 11 de Junho de 2013, 16:02
 */

#include "MultiObjective.h"
#include "BoundDbl.h"
#include "StreamPrinter.h"
#include "LinkerResults.h"

#include <string.h>
#include <cstdio>

MultiObjective::MultiObjective(int goals, const BoundDbl** bound){
    this->g = goals;
    this->bounds = bound;
    this->values = new double[goals];
    for(int i=0; i<goals; i++){
        this->values[i] = bound[i]->UB();
    }
}
MultiObjective::~MultiObjective() {
    delete[] values;
}


/**
* @return the number of goals this objective function 
*/
int MultiObjective::goals(){
    return g;
}

/**
* @return the bound valid for the absolute value this objective 
*/
const BoundDbl* MultiObjective::Bound(int i) {
   return bounds[i];
}
/**
* @return the absolute value cost this objective, interval [lb , ub]
*/
double MultiObjective::abs_value(int i) const{
    return values[i];
}
/**
* @return the relative cost this objective, interval [0 , 1]
*/
double MultiObjective::rel_value(int i) const{
    return bounds[i]->relative(values[i]);
}
/**
* set the value this objective in absolute terms
* interval [lb, ub]
* @param value
*/
void MultiObjective::set(int i, double value){
    this->values[i] = bounds[i]->valid(value);
}


void MultiObjective::Start() throw(exception){
    for(int i=0; i<g; i++){
        values[i] = bounds[i]->UB();
    }
}

void MultiObjective::Copy(Problem* mem, Objective* source) throw(exception){
    MultiObjective* obj = dynamic_cast<MultiObjective*>(source);
    memcpy(this->values, obj->values, g*sizeof(double));
}

int MultiObjective::compareTo(int i, const MultiObjective* other) const{
    return bounds[i]->compareTo(this->abs_value(i), other->abs_value(i));
}
double MultiObjective::compareToAbs(const Objective* other) const{
    const MultiObjective* obj = dynamic_cast<const MultiObjective*>(other);
    double int_this = 0;
    double int_other = 0;
    double dbl_this = 0;
    double dbl_other = 0;
    for(int i=0; i<g; i++){
        int cp = compareTo(i, obj);
        if( cp < 0 ){
            int_this++;
            dbl_this += (obj->abs_value(i) - this->abs_value(i));
        }else if( cp > 0 ){
            int_other++;
            dbl_other += (this->abs_value(i) - obj->abs_value(i));
        }
    }
    if(int_this != 0 && int_other != 0){
        return 0;
    }else if(int_this > int_other){
        return dbl_this;
    }else if(int_this < int_other){
        return -dbl_other;
    }else{
        return dbl_this - dbl_other;
    }
}
double MultiObjective::compareToRel(const Objective* other) const{
    const MultiObjective* obj = dynamic_cast<const MultiObjective*>(other);
    double int_this = 0;
    double int_other = 0;
    double dbl_this = 0;
    double dbl_other = 0;
    for(int i=0; i<g; i++){
        int cp = compareTo(i, obj);
        if( cp < 0 ){
            int_this++;
            dbl_this += (obj->rel_value(i) - this->rel_value(i));
        }else if( cp > 0 ){
            int_other++;
            dbl_other += (this->rel_value(i) - obj->rel_value(i));
        }
    }
    if(int_this != 0 && int_other != 0){
        return 0;
    }else if(int_this > int_other){
        return dbl_this;
    }else if(int_this < int_other){
        return -dbl_other;
    }else{
        return dbl_this - dbl_other;
    }
}

int MultiObjective::compareTo(const Objective* other) const{
    const MultiObjective* obj = dynamic_cast<const MultiObjective*>(other);
    int cont_this = 0;
    int cont_other = 0;
    for(int i=0; i<g; i++){
        int cp = this->compareTo(i, obj);
        if( cp < 0 ){
            cont_this++;
        }else if( cp > 0 ){
            cont_other++;
        }
    }
    return cont_this != 0 && cont_other != 0 ? 0 : cont_other - cont_this;
}

void MultiObjective::printer(Problem* mem, StreamPrinter* com) throw(exception){
    string s;
    for(int i=0; i<g; i++){
        s = "objective[";
        s+= i;
        s+= "]";
        //sprintf (buffer, "objective[%d]", i);
        com->printDbl(s, values[i]);
        //com->printDbl("objective", 1);
    }
}

void MultiObjective::results(Problem* mem, LinkerResults* com) throw(exception){
    char buffer [50];
    for(int i=0; i<g; i++){
        sprintf (buffer, "objective[%d]", i);
        com->writeDbl(buffer, values[i]);
    }
}
void MultiObjective::toString(ostream &out) throw(exception){
    bounds[0]->PrintValue(out, values[0]);
    for(int i=1; i<g; i++){
        out<<",";
        bounds[i]->PrintValue(out, values[i]);
    }
}

