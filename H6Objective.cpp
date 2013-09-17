/* 
 * File:   H6Objective.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:24
 */

#include "H6Objective.h"
#include "H6Codification.h"
#include <math.h>

H6Objective::H6Objective() {
}

H6Objective::~H6Objective() {
}

void H6Objective::Evaluate(Problem* mem, Codification* A) throw (exception) {
    H6Codification* codif = dynamic_cast<H6Codification*> (A);

	double c[4] = {1.0, 1.2, 3.0, 3.2};
	double a[4][6] = {10.0, 3.0, 17.0, 3.5, 1.7, 8.0, 0.05, 10.0, 17.0, 0.1, 8.0, 14.0, 3.0, 3.5, 1.7, 10.0, 17.0, 8.0, 17.0, 8.0, 0.05, 10.0, 0.1, 14.0};
	double p[4][6] = {0.1312, 0.1696, 0.5569, 0.0124, 0.8283, 0.5886, 0.2329, 0.4135, 0.8307, 0.3736, 0.1004, 0.9991, 0.2348, 0.1451, 0.3522, 0.2883, 0.3047, 0.665, 0.4047, 0.8828, 0.8732, 0.5743, 0.1091, 0.0381};

	double sum1 = 0;
	double sum2 = 0;	

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
				
			sum1 += a[i][j] * pow( (codif->cromo[j] - p[i][j]) , 2 ) ;
		}

		sum2 += c[i] * exp((-1)*sum1);
	}

	double fitness = (-1)*sum2;
	set(fitness);
}



Objective* H6Objective::New(Problem* mem) throw (exception) {
    return new H6Objective();
}
