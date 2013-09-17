/* 
 * File:   LocalMove.cpp
 * Author: marcio
 * 
 * Created on 8 de Março de 2013, 21:42
 */

#include "LocalMove.h"
#include "oLocalMove.h"
#include "Problem.h"
#include "Solution.h"
#include<vector>

using std::vector;

LocalMove::LocalMove(Problem* prob, vector<oLocalMove*>* moves) {
    this->prob = prob;
    this->moves = moves;
}
LocalMove::~LocalMove() {
}
Solution* LocalMove::local_search(Solution* ind) throw (exception){
    int index = prob->rmd->nextInt(moves->size());
    Solution* sol = ind->Clone(prob);
    (*moves)[index]->local_search(prob, sol->codif());
    return sol;
}


