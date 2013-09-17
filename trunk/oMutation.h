/* 
 * File:   oLocalMove.h
 * Author: marcio
 *
 * Created on 8 de Março de 2013, 21:41
 */

#ifndef OMUTATION_H
#define	OMUTATION_H

#include "Operator.h"
#include <exception>
using std::exception;

class Problem;
class Codification;
class Solution;

class oMutation : public Operator{
public:
    oMutation(){}
    virtual ~oMutation(){}
    virtual const char* name()const = 0;
    virtual void mutation(Problem* prob, Codification* ind) throw(exception) = 0;
    virtual void mutation(Problem* prob, Solution* ind) throw(exception);
private:

};

#endif	/* OLOCALMOVE_H */

