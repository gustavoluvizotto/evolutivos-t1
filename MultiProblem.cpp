/* 
 * File:   pMultiProblem.cpp
 * Author: marcio
 * 
 * Created on 11 de Junho de 2013, 15:56
 */

#include "MultiProblem.h"

MultiProblem::MultiProblem(){
    
}
MultiProblem::~MultiProblem(){
    
}
double MultiProblem::goal(int i, MultiObjective* obj){
    return obj->abs_value(i);
}
double MultiProblem::goal(int i, Solution* sol){
    MultiObjective* obj = dynamic_cast<MultiObjective*>(sol->objective);
    return obj->abs_value(i);
}
int MultiProblem::compareTo(int i, Solution* a, Solution* b){
    MultiObjective* A = dynamic_cast<MultiObjective*>(a->objective);
    MultiObjective* B = dynamic_cast<MultiObjective*>(b->objective);
    return A->compareTo(i, B);
}


