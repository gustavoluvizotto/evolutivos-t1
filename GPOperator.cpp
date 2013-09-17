/* 
 * File:   GPOperator.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "GPOperator.h"
#include "Problem.h"
#include "GPCodification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"

#include <math.h>
#include <cstdlib>

const GPOperator GPOperator::obj;

GPOperator::GPOperator() {
}

GPOperator::~GPOperator() {
}

const char* GPOperator::name()const {
    return "GP-Operator";
}

// inicializa 1 cromossomo com 4 genes, com valores double entre -1 e 1

class GPOperator::INIT : public oInitializer {

    const char* name()const {
        return "GP-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        GPCodification* codif = dynamic_cast<GPCodification*> (ind);
        srand(time(NULL));
        codif->cromo[0] = drand48()*4 - 2;	// x1 entre -2 e 2
	codif->cromo[1] = drand48()*4 - 2;	// x2 entre -2 e 2

    };
};

class GPOperator::CROSS : public oCrossover {

    const char* name()const {
        return "GP-cross-MediaAritmetica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        GPCodification* codif1 = dynamic_cast<GPCodification*> (ind1);
        GPCodification* codif2 = dynamic_cast<GPCodification*> (ind2);
        GPCodification* child = dynamic_cast<GPCodification*> (codif1->New(prob));
        for (int i = 0; i < 2; i++)
            child->cromo[i] = (codif1->cromo[i] + codif2->cromo[i]) / 2.0; //crossover média aritmética
        return child;
    };
};

/* 30% de chance de mutar cada um dos 10 genes, de 1 cromossomo */
class GPOperator::MUT : public oMutation {

    const char* name()const {
        return "GP-mut-15%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        GPCodification* codif = dynamic_cast<GPCodification*> (ind);
        for (int i = 0; i < 2; i++) {
            srand(time(NULL));
            bool muta = drand48() < 0.25; //chance de realizar mutação
            double porcentagem_mutacao = drand48() * 0.15; //se realizar mutação, essa é a taxa

            if (muta) {
                if (drand48() < 0.5) //mutar para cima ou para baixo
                    codif->cromo[i] = (1 + porcentagem_mutacao) * codif->cromo[i];
                else
                    codif->cromo[i] = (1 - porcentagem_mutacao) * codif->cromo[i];
            }
            if (codif->cromo[i] > 2.0)
                codif->cromo[i] = 2.0;
            if (codif->cromo[i] < -2.0)
                codif->cromo[i] = -2.0;
        }
    };
};

Node* GPOperator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
