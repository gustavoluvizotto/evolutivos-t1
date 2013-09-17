/* 
 * File:   ACKOperator.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "ACKOperator.h"
#include "Problem.h"
#include "ACKCodification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"
#include <cstdlib>
#include <sys/time.h>

const ACKOperator ACKOperator::obj;

ACKOperator::ACKOperator() {
}

ACKOperator::~ACKOperator() {
}

const char* ACKOperator::name()const {
    return "ACK-Operator";
}

// inicializa 1 cromossomo com 10 genes, com valores double entre -30 e +30

class ACKOperator::INIT : public oInitializer {

    const char* name()const {
        return "ACK-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        ACKCodification* codif = dynamic_cast<ACKCodification*> (ind);

        for (int i = 0; i < 10; i++) 
            codif->cromo[i] = drand48()*60 - 30;
    };
};

class ACKOperator::CROSS : public oCrossover {

    const char* name()const {
        return "ACK-cross-MediaAritmetica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        ACKCodification* codif1 = dynamic_cast<ACKCodification*> (ind1);
        ACKCodification* codif2 = dynamic_cast<ACKCodification*> (ind2);
        ACKCodification* child = dynamic_cast<ACKCodification*> (codif1->New(prob));
        for (int i = 0; i < 10; i++)
            child->cromo[i] = (codif1->cromo[i] + codif2->cromo[i]) / 2.0; //crossover média aritmética
        return child;
    };
};

/* 30% de chance de mutar cada um dos 10 genes, de 1 cromossomo */
class ACKOperator::MUT : public oMutation {

    const char* name()const {
        return "ACK-mut-30%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        ACKCodification* codif = dynamic_cast<ACKCodification*> (ind);
        for (int i = 0; i < 10; i++) {

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
            if (codif->cromo[i] > 30.0)
                codif->cromo[i] = 30.0;
            if (codif->cromo[i] < -30.0)
                codif->cromo[i] = -30.0;
        }
    };
};

Node* ACKOperator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
