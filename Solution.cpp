/* 
 * File:   pMetaSolution.cpp
 * Author: andre
 * 
 * Created on 22 de Janeiro de 2013, 14:06
 */

#include "Solution.h"

#include "Problem.h"
#include "Objective.h"
#include "Codification.h"
#include "Solution.h"

#include <stdio.h>
#include <assert.h>


Solution::Solution(Objective *objective, Codification *codification)
        throw (exception) : objective(objective), codification(codification)
{
    this->objective->Start();
}

Solution::Solution(Problem *mem)
        throw (exception) : objective(mem->NewObjective()), codification(mem->NewCodification())
{
    
};

Solution::~Solution() {
    delete objective;
    delete codification;
}
Solution* Solution::New(Problem *mem) throw (exception) {
    return new Solution(mem);
}

 Solution* Solution::New(Problem *mem, Codification *codification) throw (exception){
    return new Solution(mem->NewObjective(), codification);
}

void Solution::Evaluate(Problem *mem) throw (exception) {
    this->objective->Evaluate(mem, this->codification);
}

bool Solution::penalized() throw (exception) {
    return this->objective->penalized();
}

double Solution::compareToAbs(const Solution *other) const {
    return this->objective->compareToAbs(other->objective);
}

double Solution::compareToRel(const Solution *other) const {
    return this->objective->compareToRel(other->objective);
}

Codification *Solution::codif() {
    return codification;
}

Solution* Solution::minimum( Solution *other) {
    return compareTo(other) <= 0 ? this : other;
}
int Solution::compareTo(const Solution *other) const{
    return this->objective->compareTo(other->objective);
}
void Solution::Copy(Problem *mem, Solution *source) throw(exception){
    this->codification->Copy(mem, source->codification);
    this->objective->Copy(mem, source->objective);
}
Solution* Solution::Clone(Problem *mem) throw (exception) {
    Solution *sol = New(mem);
    sol->Copy(mem, this);
    return sol;
}
void Solution::toString(ostream &out){
    this->objective->toString(out);
}

bool operator<=(const Solution &a, const Solution &b){
    return a.compareTo(&b) <= 0;
}
bool operator<(const Solution &a, const Solution &b){
    return a.compareTo(&b) < 0;
}
bool operator==(const Solution &a, const Solution &b){
    return a.compareTo(&b) == 0;
}
bool operator>(const Solution &a, const Solution &b){
    return a.compareTo(&b) > 0;
}
bool operator>=(const Solution &a, const Solution &b){
    return a.compareTo(&b) >= 0;
}

