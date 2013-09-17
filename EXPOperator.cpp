/* 
 * File:   EXPOperator.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "EXPOperator.h"
#include "Problem.h"
#include "EXPCodification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"

#include <math.h>
#include <cstdlib>

const EXPOperator EXPOperator::obj;

EXPOperator::EXPOperator() {
}

EXPOperator::~EXPOperator() {
}

const char* EXPOperator::name()const {
    return "EXP-Operator";
}

// inicializa 1 cromossomo com 4 genes, com valores double entre -1 e 1

class EXPOperator::INIT : public oInitializer {

    const char* name()const {
        return "EXP-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        EXPCodification* codif = dynamic_cast<EXPCodification*> (ind);
        srand(time(NULL));
        for (int i = 0; i < 10; i++)
            codif->cromo[i] = drand48()*2.0 - 1.0;		// de -1 a 1
    };
};

class EXPOperator::CROSS : public oCrossover {

    const char* name()const {
        return "EXP-cross-MediaAritmetica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        EXPCodification* codif1 = dynamic_cast<EXPCodification*> (ind1);
        EXPCodification* codif2 = dynamic_cast<EXPCodification*> (ind2);
        EXPCodification* child = dynamic_cast<EXPCodification*> (codif1->New(prob));
        for (int i = 0; i < 10; i++)
            child->cromo[i] = (codif1->cromo[i] + codif2->cromo[i]) / 2.0; //crossover média aritmética
        return child;
    };
};

/* 30% de chance de mutar cada um dos 10 genes, de 1 cromossomo */
class EXPOperator::MUT : public oMutation {

    const char* name()const {
        return "EXP-mut-15%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        EXPCodification* codif = dynamic_cast<EXPCodification*> (ind);
        for (int i = 0; i < 10; i++) {
            srand(time(NULL));
            bool muta = drand48() < 0.25; //chance de realizar mutação
            double porcentagem_mutacao = drand48() * 0.15; //se realizar mutação, essa é a taxa

            if (muta) {
                if (drand48() < 0.5) //mutar para cima ou para baixo
                    codif->cromo[i] = (1 + porcentagem_mutacao) * codif->cromo[i];
                else
                    codif->cromo[i] = (1 - porcentagem_mutacao) * codif->cromo[i];
            }
            if (codif->cromo[i] > 1.0)
                codif->cromo[i] = 1.0;
            if (codif->cromo[i] < -1.0)
                codif->cromo[i] = -1.0;
        }
    };
};

Node* EXPOperator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
