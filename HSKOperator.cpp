/* 
 * File:   HSKOperator.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "HSKOperator.h"
#include "Problem.h"
#include "HSKCodification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"

#include <cstdlib>

const HSKOperator HSKOperator::obj;

HSKOperator::HSKOperator() {
}

HSKOperator::~HSKOperator() {
}

const char* HSKOperator::name()const {
    return "HSK-Operator";
}

/* inicializa 1 cromossomo com 2 genes
 * primeiro gene (x1) entre 0 e 5
 * segundo gene (x2) entre 0 e 6
 */
class HSKOperator::INIT : public oInitializer {

    const char* name()const {
        return "HSK-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        HSKCodification* codif = dynamic_cast<HSKCodification*> (ind);

        srand(time(NULL));
        codif->cromo[0] = drand48()*5; /*x1*/
        codif->cromo[1] = drand48()*6; /*x2*/
    };
};

class HSKOperator::CROSS : public oCrossover {

    const char* name()const {
        return "HSK-cross-MediaAritmetica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        HSKCodification* codif1 = dynamic_cast<HSKCodification*> (ind1);
        HSKCodification* codif2 = dynamic_cast<HSKCodification*> (ind2);
        HSKCodification* child = dynamic_cast<HSKCodification*> (codif1->New(prob));

        child->cromo[0] = (codif1->cromo[0] + codif2->cromo[0]) / 2.0; //crossover média aritmética
        child->cromo[1] = (codif1->cromo[1] + codif2->cromo[1]) / 2.0; //crossover média aritmética

        return child;
    };
};

/* 30% de chance de mutar cada um dos 2 genes, de 1 cromossomo */
class HSKOperator::MUT : public oMutation {

    const char* name()const {
        return "HSK-mut-30%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        HSKCodification* codif = dynamic_cast<HSKCodification*> (ind);
        for (int i = 0; i < 2; i++) {
            srand(time(NULL));
            bool muta = drand48() < 0.25; //chance de realizar mutação
            double porcentagem_mutacao = drand48() * 0.3; //se realizar mutação, essa é a taxa

            if (muta) {
                if (drand48() < 0.5) //mutar para cima ou para baixo
                    codif->cromo[i] = (1 + porcentagem_mutacao) * codif->cromo[i];
                else
                    codif->cromo[i] = (1 - porcentagem_mutacao) * codif->cromo[i];
            }
        }
        if (codif->cromo[0] > 5.0)
            codif->cromo[0] = 5.0;
        if (codif->cromo[0] < 0.0)
            codif->cromo[0] = 0.0;
        if (codif->cromo[1] > 6.0)
            codif->cromo[1] = 6.0;
        if (codif->cromo[1] < 0.0)
            codif->cromo[1] = 0.0;
    };
};

Node* HSKOperator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
