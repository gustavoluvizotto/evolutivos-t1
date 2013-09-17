/* 
 * File:   H6Operator.cpp
 * Author: beatriz
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "H6Operator.h"
#include "Problem.h"
#include "H6Codification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"

#include <math.h>
#include <cstdlib>

const H6Operator H6Operator::obj;

H6Operator::H6Operator() {
}

H6Operator::~H6Operator() {
}

const char* H6Operator::name()const {
    return "H6-Operator";
}

// inicializa 1 cromossomo com 4 genes, com valores double entre -1 e 1

class H6Operator::INIT : public oInitializer {

    const char* name()const {
        return "H6-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        H6Codification* codif = dynamic_cast<H6Codification*> (ind);
        srand(time(NULL));
        for (int i = 0; i < 6; i++)
            codif->cromo[i] = drand48();		// de 0 a 1
    };
};

class H6Operator::CROSS : public oCrossover {

    const char* name()const {
        return "H6-cross-MediaGeometrica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        H6Codification* codif1 = dynamic_cast<H6Codification*> (ind1);
        H6Codification* codif2 = dynamic_cast<H6Codification*> (ind2);
        H6Codification* child = dynamic_cast<H6Codification*> (codif1->New(prob));
        for (int i = 0; i < 6; i++)
            child->cromo[i] = sqrt(codif1->cromo[i] * codif2->cromo[i]); //crossover média geometrica
        return child;
    };
};

/* 30% de chance de mutar cada um dos 10 genes, de 1 cromossomo */
class H6Operator::MUT : public oMutation {

    const char* name()const {
        return "H6-mut-35%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        H6Codification* codif = dynamic_cast<H6Codification*> (ind);
        for (int i = 0; i < 6; i++) {
            srand(time(NULL));
            bool muta = drand48() < 0.6; //chance de realizar mutação
            double porcentagem_mutacao = drand48() * 0.35; //se realizar mutação, essa é a taxa

            if (muta) {
                if (drand48() < 0.4) //mutar para cima ou para baixo
                    codif->cromo[i] = (1 + porcentagem_mutacao) * codif->cromo[i];
                else
                    codif->cromo[i] = (1 - porcentagem_mutacao) * codif->cromo[i];
            }
            if (codif->cromo[i] > 1.0)
                codif->cromo[i] = 1.0;
            if (codif->cromo[i] < 0.0)
                codif->cromo[i] = 0.0;
        }
    };
};

Node* H6Operator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
