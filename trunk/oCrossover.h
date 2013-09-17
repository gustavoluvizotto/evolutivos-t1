/* 
 * File:   oLocalMove.h
 * Author: marcio
 *
 * Created on 8 de Março de 2013, 21:41
 */

#ifndef OCROSSOVER_H
#define	OCROSSOVER_H

#include "Operator.h"
#include <exception>
using std::exception;

class Problem;
class Codification;
class Solution;

class oCrossover : public Operator{
public:
    oCrossover(){}
    virtual ~oCrossover(){}
    virtual const char* name()const = 0;
    virtual Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw(exception) = 0;
    virtual Solution* crossover(Problem* prob, Solution* ind1, Solution* ind2) throw(exception);
private:
};

#endif	/* OLOCALMOVE_H */

