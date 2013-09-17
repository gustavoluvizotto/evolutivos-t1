/* 
 * File:   GPObjective.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "GPObjective.h"
#include "GPCodification.h"
#include <math.h>

GPObjective::GPObjective() {
}

GPObjective::~GPObjective() {
}

void GPObjective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    GPCodification* codif = dynamic_cast<GPCodification*> (A);

	double x1 = codif->cromo[0];
	double x2 = codif->cromo[1];

	double termo1 = pow((x1+x2+1),2);
	double termo2 = 19 - 14*x1 + 3*pow(x1,2) - 14*x2 + 6*x1*x2 + 3*pow(x2,2);
	double termo3 = pow((2*x1 - 3*x2),2);
	double termo4 = 18 - 32*x1 + 12*pow(x1,2) + 48*x2 - 36*x1*x2 + 27*pow(x2,2);

	double fitness = ( 1 + termo1*termo2 ) * (30 + termo3*termo4);
	set(fitness);
}

Objective* GPObjective::New(Problem* mem) throw (exception) {
    return new GPObjective();
}
