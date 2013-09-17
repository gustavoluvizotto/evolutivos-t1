/* 
 * File:   KLOperator.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "KLOperator.h"
#include "Problem.h"
#include "KLCodification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"

#include <cstdlib>

const KLOperator KLOperator::obj;

KLOperator::KLOperator() {
}

KLOperator::~KLOperator() {
}

const char* KLOperator::name()const {
    return "KL-Operator";
}

/* inicializa 1 cromossomo com 4 genes, com valores double entre 0 e 0.42 */
class KLOperator::INIT : public oInitializer {

    const char* name()const {
        return "KL-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        KLCodification* codif = dynamic_cast<KLCodification*> (ind);
        
        srand(time(NULL));
        for (int i = 0; i < 4; i++)
            codif->cromo[i] = drand48()*0.42;
    };
};

class KLOperator::CROSS : public oCrossover {

    const char* name()const {
        return "KL-cross-MediaAritmetica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        KLCodification* codif1 = dynamic_cast<KLCodification*> (ind1);
        KLCodification* codif2 = dynamic_cast<KLCodification*> (ind2);
        KLCodification* child = dynamic_cast<KLCodification*> (codif1->New(prob));
        
        for (int i = 0; i < 4; i++)
            child->cromo[i] = (codif1->cromo[i] + codif2->cromo[i]) / 2.0; //crossover média aritmética
        return child;
    };
};

/* 30% de chance de mutar cada um dos 3 genes, de 1 cromossomo */
class KLOperator::MUT : public oMutation {

    const char* name()const {
        return "KL-mut-30%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        KLCodification* codif = dynamic_cast<KLCodification*> (ind);
        for (int i = 0; i < 4; i++) {
            srand(time(NULL));
            bool muta = drand48() < 0.25; //chance de realizar mutação
            double porcentagem_mutacao = drand48() * 0.3; //se realizar mutação, essa é a taxa

            if (muta) {
                if (drand48() < 0.5) //mutar para cima ou para baixo
                    codif->cromo[i] = (1 + porcentagem_mutacao) * codif->cromo[i];
                else
                    codif->cromo[i] = (1 - porcentagem_mutacao) * codif->cromo[i];
            }
            if (codif->cromo[i] > 0.42)
                codif->cromo[i] = 0.42;
            if (codif->cromo[i] < 0.0)
                codif->cromo[i] = 0.0;
        }
    };
};

Node* KLOperator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
