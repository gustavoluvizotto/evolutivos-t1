#include "oInitializer.h"
#include "Problem.h"
#include "Solution.h"

void oInitializer::initialize(Problem* prob, Solution* ind)  throw(exception){
    initialize(prob, ind->codif());
}

