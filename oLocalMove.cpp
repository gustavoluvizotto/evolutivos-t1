#include "oLocalMove.h"
#include "Problem.h"
#include "Solution.h"
#include "Codification.h"

Solution* oLocalMove::local_search(Problem* prob, Solution* ind)  throw(exception){
    Codification* neighbor = ind->codif()->Clone(prob);
    local_search(prob, neighbor);
    return prob->NewSolution(neighbor);
}

