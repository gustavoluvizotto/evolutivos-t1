#include "oCrossover.h"
#include "Problem.h"
#include "Solution.h"
#include "Codification.h"

Solution* oCrossover::crossover(Problem* prob, Solution* ind1, Solution* ind2)  throw(exception){
    Codification* child = crossover(prob, ind1->codif(), ind2->codif());
    return prob->NewSolution(child);
}

