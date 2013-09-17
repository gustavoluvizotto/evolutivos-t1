/* 
 * File:   oLocalMove.h
 * Author: marcio
 *
 * Created on 8 de Março de 2013, 21:41
 */

#ifndef OLOCALMOVE_H
#define	OLOCALMOVE_H

#include "Operator.h"
#include <exception>
using std::exception;

class Problem;
class Codification;
class Solution;

class oLocalMove : public Operator{
public:
    oLocalMove(){}
    virtual ~oLocalMove(){}
    virtual const char* name()const = 0;
    virtual void local_search(Problem* prob, Codification* ind) throw(exception) = 0;
    virtual Solution* local_search(Problem* prob, Solution* ind)  throw(exception);
private:

};

#endif	/* OLOCALMOVE_H */

