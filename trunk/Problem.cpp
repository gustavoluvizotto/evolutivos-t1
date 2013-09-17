/* 
 * File:   pMetaProblem.cpp
 * Author: andre
 * 
 * Created on 22 de Janeiro de 2013, 14:04
 */

#include "Problem.h"
#include "Solution.h"
#include "Instance.h"
#include "Best.h"
#include "uRandom.h"
#include "LinkerNodes.h"
#include "ComDefines.h"

Problem::Problem() {
    //rmd = new uRandom();
}
Problem::~Problem() {}

void Problem::construct() throw(exception){
    best = NewBest();    
    rmd = new uRandom();
}

void Problem::services(LinkerNodes *com) throw(exception){
    com->add(best);
}
Solution *Problem::NewSolution() throw(exception) { 
    return new Solution(NewObjective(),NewCodification());
}
Solution *Problem::NewSolution(Codification *codif) throw(exception) {
    return new Solution(this->NewObjective(), codif);
}
void Problem::evaluate(Solution* sol) throw(exception){
    sol->Evaluate(this);
    if(best!=NULL){
        best->addBetter(this, sol);
    }
}
Best* Problem::NewBest(){
    return NULL;
}

void Problem::parameters(LinkerParameters *com) throw(exception) {}
bool Problem::validation(LinkerValidations *com) throw(exception) {return true;}
void Problem::load() throw(exception) {}
void Problem::start() throw(exception) {}
void Problem::results(LinkerResults *com) throw(exception) {} 

