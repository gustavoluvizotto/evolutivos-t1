/* 
 * File:   pSingleObjective.cpp
 * Author: marcio
 * 
 * Created on 8 de Abril de 2013, 16:51
 */

#include "SingleObjective.h"
#include "BoundDbl.h"
#include "StreamPrinter.h"
#include "LinkerResults.h"

SingleObjective::SingleObjective(){
    this->bound = &BoundDbl::def;
    this->value = bound->UB();
}
SingleObjective::SingleObjective(const BoundDbl* bound) {
    this->bound = bound;
    this->value = bound->UB();
}

SingleObjective::~SingleObjective() {
    
}


const BoundDbl* SingleObjective::Bound() {
   return bound;
}

double SingleObjective::abs_value() const{
   return value;
}
double SingleObjective::rel_value() const{
   return bound->relative(value);
}

void SingleObjective::set(double value){
   this->value = bound->valid(value);
}

void SingleObjective::Start() throw(exception){
    value = bound->UB();
}

void SingleObjective::Copy(Problem* mem, Objective* source) throw(exception){
    SingleObjective* obj = dynamic_cast<SingleObjective*>(source);
    this->value = obj->abs_value();
}

double SingleObjective::compareToAbs(const Objective* other) const{
    const SingleObjective* obj = dynamic_cast<const SingleObjective*>(other);
    if(this->compareTo(other)!=0){
        return this->abs_value() - obj->abs_value();
    }
    return 0;
}

double SingleObjective::compareToRel(const Objective* other) const{
    const SingleObjective* obj = dynamic_cast<const SingleObjective*>(other);
    if(this->compareTo(other)!=0){
        return this->rel_value() - obj->rel_value();
    }
    return 0;
}

int SingleObjective::compareTo(const Objective* other) const{
    const SingleObjective* obj = dynamic_cast<const SingleObjective*>(other);
    return bound->compareTo(this->abs_value(), obj->abs_value());
}

void SingleObjective::printer(Problem* mem, StreamPrinter* com) throw(exception){
    com->printDbl("objective", value);
}

void SingleObjective::results(Problem* mem, LinkerResults* com) throw(exception){
    com->writeDbl("objective", value);
}
void SingleObjective::toString(ostream &out) throw(exception){
    bound->PrintValue(out, value);
}

