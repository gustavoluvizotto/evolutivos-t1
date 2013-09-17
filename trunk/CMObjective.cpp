/* 
 * File:   CMObjective.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "CMObjective.h"
#include "CMCodification.h"
#include <math.h>

CMObjective::CMObjective() {
}

CMObjective::~CMObjective() {
}

void CMObjective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    CMCodification* codif = dynamic_cast<CMCodification*> (A);

    int n = 4;
    double sum1 = 0;
    double sum2 = 0;

    for (int i = 0; i < n; i++) {

	sum1 += cos(5 * M_PI * codif->cromo[i]);
	sum2 += codif->cromo[i] * codif->cromo[i];
    }

	// maximizar funcao = minizar o inverso dela
    double fitness = -(0.1*sum1 - sum2);		// 0.1*SOMAT{cos(5 * PI * xi)} - SOMAT{xi²}
    set(fitness);
}

Objective* CMObjective::New(Problem* mem) throw (exception) {
    return new CMObjective();
}
