/* 
 * File:   GRPObjective.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "GRPObjective.h"
#include "GRPCodification.h"
#include <math.h>

GRPObjective::GRPObjective() {
}

GRPObjective::~GRPObjective() {
}

void GRPObjective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    GRPCodification* codif = dynamic_cast<GRPCodification*> (A);

	double u[99];
	double x1 = codif->cromo[0];
	double x2 = codif->cromo[1];
	double x3 = codif->cromo[2];

	double aux1 = 0;
	double aux2 = 0;

	double sum = 0;
	int i = 0;

	for (i = 1; i <= 99; i++) {

		u[i] = 25 + pow( ( (-50)*log(0.01*i) ), 0.67 );
		
		aux1 = (-1) * ( pow( (u[i]-x2) , x3 ) / x1 );
		aux2 = exp(aux1) - 0.01*i;

		sum += pow(aux2, 2);
	}

	double fitness = sum;
	set(fitness);
}

Objective* GRPObjective::New(Problem* mem) throw (exception) {
    return new GRPObjective();
}
