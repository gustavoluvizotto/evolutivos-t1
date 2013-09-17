/* 
 * File:   LM2Operator.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "LM2Operator.h"
#include "Problem.h"
#include "LM2Codification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"

#include <cstdlib>

const LM2Operator LM2Operator::obj;

LM2Operator::LM2Operator() {
}

LM2Operator::~LM2Operator() {
}

const char* LM2Operator::name()const {
    return "LM2-Operator";
}

/* inicializa 1 cromossomo com 10 genes entre -5 e 5 */
class LM2Operator::INIT : public oInitializer {

    const char* name()const {
        return "LM2-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        LM2Codification* codif = dynamic_cast<LM2Codification*> (ind);

        srand(time(NULL));
        for (int i = 0; i < 10; i++)
            codif->cromo[0] = drand48()*10.0 - 5.0; /*x1*/

    };
};

class LM2Operator::CROSS : public oCrossover {

    const char* name()const {
        return "LM2-cross-MediaAritmetica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        LM2Codification* codif1 = dynamic_cast<LM2Codification*> (ind1);
        LM2Codification* codif2 = dynamic_cast<LM2Codification*> (ind2);
        LM2Codification* child = dynamic_cast<LM2Codification*> (codif1->New(prob));

        for (int i = 0; i < 10; i++)
            child->cromo[i] = (codif1->cromo[i] + codif2->cromo[i]) / 2.0; //crossover média aritmética

        return child;
    };
};

/* 30% de chance de mutar cada um dos 10 genes, de 1 cromossomo */
class LM2Operator::MUT : public oMutation {

    const char* name()const {
        return "LM2-mut-30%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        LM2Codification* codif = dynamic_cast<LM2Codification*> (ind);
        for (int i = 0; i < 10; i++) {
            srand(time(NULL));
            bool muta = drand48() < 0.25; //chance de realizar mutação
            double porcentagem_mutacao = drand48() * 0.3; //se realizar mutação, essa é a taxa

            if (muta) {
                if (drand48() < 0.5) //mutar para cima ou para baixo
                    codif->cromo[i] = (1 + porcentagem_mutacao) * codif->cromo[i];
                else
                    codif->cromo[i] = (1 - porcentagem_mutacao) * codif->cromo[i];
            }
            if (codif->cromo[i] > 5.0)
                codif->cromo[i] = 5.0;
            if (codif->cromo[i] < -5.0)
                codif->cromo[i] = -5.0;
        }
    };
};

Node* LM2Operator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
