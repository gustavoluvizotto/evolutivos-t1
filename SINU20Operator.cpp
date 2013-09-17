/* 
 * File:   SINU20Operator.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "SINU20Operator.h"
#include "Problem.h"
#include "SINU20Codification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"
#include <cstdlib>
#include <sys/time.h>

const SINU20Operator SINU20Operator::obj;

SINU20Operator::SINU20Operator() {
}

SINU20Operator::~SINU20Operator() {
}

const char* SINU20Operator::name()const {
    return "SINU20-Operator";
}

/* inicializa 1 cromossomo com 20 genes, com valores double entre 0 e +180 */
class SINU20Operator::INIT : public oInitializer {

    const char* name()const {
        return "SINU20-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        SINU20Codification* codif = dynamic_cast<SINU20Codification*> (ind);

        timeval t1;
        gettimeofday(&t1, NULL);
        srand48(t1.tv_usec * t1.tv_sec);

        for (int i = 0; i < 20; i++)
            codif->cromo[i] = drand48()*180;
    };
};

class SINU20Operator::CROSS : public oCrossover {

    const char* name()const {
        return "SINU20-cross-MediaAritmetica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        SINU20Codification* codif1 = dynamic_cast<SINU20Codification*> (ind1);
        SINU20Codification* codif2 = dynamic_cast<SINU20Codification*> (ind2);
        SINU20Codification* child = dynamic_cast<SINU20Codification*> (codif1->New(prob));
        for (int i = 0; i < 20; i++)
            child->cromo[i] = (codif1->cromo[i] + codif2->cromo[i]) / 2.0; //crossover média aritmética
        return child;
    };
};

/* 30% de chance de mutar cada um dos genes */
class SINU20Operator::MUT : public oMutation {

    const char* name()const {
        return "SINU20-mut-30%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        SINU20Codification* codif = dynamic_cast<SINU20Codification*> (ind);
        for (int i = 0; i < 20; i++) {

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
            if (codif->cromo[i] > 180.0)
                codif->cromo[i] = 180.0;
            if (codif->cromo[i] < 0.0)
                codif->cromo[i] = 0.0;
        }
    };
};

Node* SINU20Operator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
