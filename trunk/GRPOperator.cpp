/* 
 * File:   GRPOperator.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "GRPOperator.h"
#include "Problem.h"
#include "GRPCodification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"

#include <math.h>
#include <cstdlib>

const GRPOperator GRPOperator::obj;

GRPOperator::GRPOperator() {
}

GRPOperator::~GRPOperator() {
}

const char* GRPOperator::name()const {
    return "GRP-Operator";
}

// inicializa 1 cromossomo com 4 genes, com valores double entre -1 e 1

class GRPOperator::INIT : public oInitializer {

    const char* name()const {
        return "GRP-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        GRPCodification* codif = dynamic_cast<GRPCodification*> (ind);
        srand(time(NULL));
        
	codif->cromo[0] = drand48()*99.9 + 0.1 ;	// x1 entre 0,1 e 100
	codif->cromo[1] = drand48()*25.6 ;		// x2 entre 0 e 25,6
	codif->cromo[2] = drand48()*5 ;		 	// x3 entre 0 e 5

    };
};

class GRPOperator::CROSS : public oCrossover {

    const char* name()const {
        return "GRP-cross-MediaGeometrica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        GRPCodification* codif1 = dynamic_cast<GRPCodification*> (ind1);
        GRPCodification* codif2 = dynamic_cast<GRPCodification*> (ind2);
        GRPCodification* child = dynamic_cast<GRPCodification*> (codif1->New(prob));
        for (int i = 0; i < 3; i++)
            child->cromo[i] = sqrt(codif1->cromo[i] * codif2->cromo[i]); //crossover média geometrica
        return child;
    };
};

/* 30% de chance de mutar cada um dos 10 genes, de 1 cromossomo */
class GRPOperator::MUT : public oMutation {

    const char* name()const {
        return "GRP-mut-25%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        GRPCodification* codif = dynamic_cast<GRPCodification*> (ind);
        for (int i = 0; i < 3; i++) {
            srand(time(NULL));
            bool muta = drand48() < 0.5; //chance de realizar mutação
            double porcentagem_mutacao = drand48() * 0.25; //se realizar mutação, essa é a taxa

            if (muta) {
                if (drand48() < 0.4) //mutar para cima ou para baixo
                    codif->cromo[i] = (1 + porcentagem_mutacao) * codif->cromo[i];
                else
                    codif->cromo[i] = (1 - porcentagem_mutacao) * codif->cromo[i];
            }
	}
            
	if (codif->cromo[0] > 100.0)
		codif->cromo[0] = 100.0;
        if (codif->cromo[0] < 0.1)
                codif->cromo[0] = 0.1;

	if (codif->cromo[1] > 25.6)
		codif->cromo[1] = 25.6;
        if (codif->cromo[1] < 0.0)
                codif->cromo[1] = 0;

	if (codif->cromo[2] > 5.0)
		codif->cromo[2] = 5.0;
        if (codif->cromo[2] < 0.0)
                codif->cromo[2] = 0.0;
    };
};

Node* GRPOperator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
