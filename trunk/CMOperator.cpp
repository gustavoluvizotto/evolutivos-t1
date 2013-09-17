/* 
 * File:   CMOperator.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "CMOperator.h"
#include "Problem.h"
#include "CMCodification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"

#include <math.h>
#include <cstdlib>

const CMOperator CMOperator::obj;

CMOperator::CMOperator() {
}

CMOperator::~CMOperator() {
}

const char* CMOperator::name()const {
    return "CM-Operator";
}

// inicializa 1 cromossomo com 4 genes, com valores double entre -1 e 1

class CMOperator::INIT : public oInitializer {

    const char* name()const {
        return "CM-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        CMCodification* codif = dynamic_cast<CMCodification*> (ind);
        srand(time(NULL));
        for (int i = 0; i < 4; i++)
            codif->cromo[i] = drand48()*2.0 - 1.0;		// de -1 a 1
    };
};

class CMOperator::CROSS : public oCrossover {

    const char* name()const {
        return "CM-cross-MediaAritmetica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        CMCodification* codif1 = dynamic_cast<CMCodification*> (ind1);
        CMCodification* codif2 = dynamic_cast<CMCodification*> (ind2);
        CMCodification* child = dynamic_cast<CMCodification*> (codif1->New(prob));
        for (int i = 0; i < 4; i++)
            child->cromo[i] = (codif1->cromo[i] + codif2->cromo[i]) / 2.0; //crossover média aritmetica
        return child;
    };
};

/* 30% de chance de mutar cada um dos 10 genes, de 1 cromossomo */
class CMOperator::MUT : public oMutation {

    const char* name()const {
        return "CM-mut-10%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        CMCodification* codif = dynamic_cast<CMCodification*> (ind);
        for (int i = 0; i < 4; i++) {
            srand(time(NULL));
            bool muta = drand48() < 0.5; //chance de realizar mutação
            double porcentagem_mutacao = drand48() * 0.1; //se realizar mutação, essa é a taxa

            if (muta) {
                if (drand48() < 0.6) //mutar para cima ou para baixo
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

Node* CMOperator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
