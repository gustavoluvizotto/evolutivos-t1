/* 
 * File:   HVOperator.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "HVOperator.h"
#include "Problem.h"
#include "HVCodification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"

#include <cstdlib>

const HVOperator HVOperator::obj;

HVOperator::HVOperator() {
}

HVOperator::~HVOperator() {
}

const char* HVOperator::name()const {
    return "HV-Operator";
}

/* inicializa 1 cromossomo com 3 genes, sendo cada um entre -10 e 10
 */
class HVOperator::INIT : public oInitializer {

    const char* name()const {
        return "HV-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        HVCodification* codif = dynamic_cast<HVCodification*> (ind);

        srand(time(NULL));
        for (int i = 0; i < 3; i++)
            codif->cromo[i] = drand48()*20 - 10; /*entre -10 e 10*/
    };
};

class HVOperator::CROSS : public oCrossover {

    const char* name()const {
        return "HV-cross-MediaAritmetica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        HVCodification* codif1 = dynamic_cast<HVCodification*> (ind1);
        HVCodification* codif2 = dynamic_cast<HVCodification*> (ind2);
        HVCodification* child = dynamic_cast<HVCodification*> (codif1->New(prob));

        for (int i = 0; i < 3; i++)
            child->cromo[i] = (codif1->cromo[i] + codif2->cromo[i]) / 2.0; /* crossover media aritimetica */

        return child;
    };
};

/* 30% de chance de mutar cada um dos 2 genes, de 1 cromossomo */
class HVOperator::MUT : public oMutation {

    const char* name()const {
        return "HV-mut-30%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        HVCodification* codif = dynamic_cast<HVCodification*> (ind);
        for (int i = 0; i < 3; i++) {
            srand(time(NULL));
            bool muta = drand48() < 0.25; //chance de realizar mutação
            double porcentagem_mutacao = drand48() * 0.3; //se realizar mutação, essa é a taxa

            if (muta) {
                if (drand48() < 0.5) //mutar para cima ou para baixo
                    codif->cromo[i] = (1 + porcentagem_mutacao) * codif->cromo[i];
                else
                    codif->cromo[i] = (1 - porcentagem_mutacao) * codif->cromo[i];
            }
            if (codif->cromo[i] > 10.0)
                codif->cromo[i] = 10.0;
            if (codif->cromo[i] < -10.0)
                codif->cromo[i] = -10.0;
        }
    };
};

Node* HVOperator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
