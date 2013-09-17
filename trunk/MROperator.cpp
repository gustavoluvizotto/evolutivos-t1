/* 
 * File:   MROperator.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "MROperator.h"
#include "Problem.h"
#include "MRCodification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"
#include <cstdlib>
#include <sys/time.h>

const MROperator MROperator::obj;

MROperator::MROperator() {
}

MROperator::~MROperator() {
}

const char* MROperator::name()const {
    return "MR-Operator";
}

/* inicializa 1 cromossomo com 3 genes, com valores double entre -10 e +10 */
class MROperator::INIT : public oInitializer {

    const char* name()const {
        return "MR-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        MRCodification* codif = dynamic_cast<MRCodification*> (ind);

        timeval t1;
        gettimeofday(&t1, NULL);
        srand48(t1.tv_usec * t1.tv_sec);

        for (int i = 0; i < 3; i++)
            codif->cromo[i] = drand48()*20 - 10;
    };
};

class MROperator::CROSS : public oCrossover {

    const char* name()const {
        return "MR-cross-MediaAritmetica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        MRCodification* codif1 = dynamic_cast<MRCodification*> (ind1);
        MRCodification* codif2 = dynamic_cast<MRCodification*> (ind2);
        MRCodification* child = dynamic_cast<MRCodification*> (codif1->New(prob));
        for (int i = 0; i < 3; i++)
            child->cromo[i] = (codif1->cromo[i] + codif2->cromo[i]) / 2.0; //crossover média aritmética
        return child;
    };
};

/* 30% de chance de mutar cada um dos 3 genes, de 1 cromossomo */
class MROperator::MUT : public oMutation {

    const char* name()const {
        return "MR-mut-30%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        MRCodification* codif = dynamic_cast<MRCodification*> (ind);
        for (int i = 0; i < 3; i++) {

            timeval t1;
            gettimeofday(&t1, NULL);
            srand48(t1.tv_usec * t1.tv_sec);

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

Node* MROperator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
