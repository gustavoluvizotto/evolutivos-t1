/* 
 * File:   WPOperator.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "WPOperator.h"
#include "Problem.h"
#include "WPCodification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"
#include <cstdlib>
#include <sys/time.h>

const WPOperator WPOperator::obj;

WPOperator::WPOperator() {
}

WPOperator::~WPOperator() {
}

const char* WPOperator::name()const {
    return "WP-Operator";
}

/* inicializa 1 cromossomo com 4 genes, com valores double entre -10 e +10 */
class WPOperator::INIT : public oInitializer {

    const char* name()const {
        return "WP-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        WPCodification* codif = dynamic_cast<WPCodification*> (ind);

        timeval t1;
        gettimeofday(&t1, NULL);
        srand48(t1.tv_usec * t1.tv_sec);

        for (int i = 0; i < 4; i++)
            codif->cromo[i] = drand48()*20 - 10;
    };
};

class WPOperator::CROSS : public oCrossover {

    const char* name()const {
        return "WP-cross-MediaAritmetica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        WPCodification* codif1 = dynamic_cast<WPCodification*> (ind1);
        WPCodification* codif2 = dynamic_cast<WPCodification*> (ind2);
        WPCodification* child = dynamic_cast<WPCodification*> (codif1->New(prob));
        for (int i = 0; i < 4; i++)
            child->cromo[i] = (codif1->cromo[i] + codif2->cromo[i]) / 2.0; //crossover média aritmética
        return child;
    };
};

/* 30% de chance de mutar cada um dos genes */
class WPOperator::MUT : public oMutation {

    const char* name()const {
        return "WP-mut-30%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        WPCodification* codif = dynamic_cast<WPCodification*> (ind);
        for (int i = 0; i < 4; i++) {

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

Node* WPOperator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
