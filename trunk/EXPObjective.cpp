/* 
 * File:   EXPObjective.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "EXPObjective.h"
#include "EXPCodification.h"
#include <math.h>

EXPObjective::EXPObjective() {
}

EXPObjective::~EXPObjective() {
}

void EXPObjective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    EXPCodification* codif = dynamic_cast<EXPCodification*> (A);


	int n = 10;
	double sum1 = 0;

	for (int i = 0; i < n; i++) {
	
		sum1 += codif->cromo[i] * codif->cromo[i];
	}

	// maximizar funcao = minimizar inverso dela
	double fitness = -( exp((-0.5)*sum1) );		// exp( -0,5 * SOMAT{xi²} )
	set(fitness);
}

Objective* EXPObjective::New(Problem* mem) throw (exception) {
    return new EXPObjective();
}
