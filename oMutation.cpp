#include "oMutation.h"
#include "Problem.h"
#include "Solution.h"

void oMutation::mutation(Problem* prob, Solution* ind)  throw(exception){
    mutation(prob, ind->codif());
}

