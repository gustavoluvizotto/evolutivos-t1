/* 
 * File:   oInitializer.h
 * Author: marcio
 *
 * Created on 8 de Março de 2013, 21:39
 */

#ifndef OINITIALIZER_H
#define	OINITIALIZER_H

#include "Operator.h"
#include <exception>
using std::exception;

class Problem;
class Codification;
class Solution;

class oInitializer : public Operator{
public:
    oInitializer(){};
    virtual ~oInitializer(){};
    virtual const char* name()const = 0;
    virtual void initialize(Problem* prob, Codification* ind) throw(exception) = 0;
    virtual void initialize(Problem* prob, Solution* ind) throw(exception);
private:
};

#endif	/* OINITIALIZER_H */

