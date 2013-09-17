/* 
 * File:   BROperator.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "BROperator.h"
#include "Problem.h"
#include "BRCodification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"
#include <cstdlib>
#include <sys/time.h>

const BROperator BROperator::obj;

BROperator::BROperator() {
}

BROperator::~BROperator() {
}

const char* BROperator::name()const {
    return "BR-Operator";
}

/* inicializa 1 cromossomo com 2 genes, com valores double entre (-5;10) e (0;15) */
class BROperator::INIT : public oInitializer {

    const char* name()const {
        return "BR-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        BRCodification* codif = dynamic_cast<BRCodification*> (ind);

        timeval t1;
        gettimeofday(&t1, NULL);
        srand48(t1.tv_usec * t1.tv_sec);

        codif->cromo[0] = drand48()*15 - 5;
        codif->cromo[1] = drand48()*15;
    };
};

class BROperator::CROSS : public oCrossover {

    const char* name()const {
        return "BR-cross-MediaAritmetica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        BRCodification* codif1 = dynamic_cast<BRCodification*> (ind1);
        BRCodification* codif2 = dynamic_cast<BRCodification*> (ind2);
        BRCodification* child = dynamic_cast<BRCodification*> (codif1->New(prob));
        for (int i = 0; i < 2; i++)
            child->cromo[i] = (codif1->cromo[i] + codif2->cromo[i]) / 2.0; //crossover média aritmética
        return child;
    };
};

/* 30% de chance de mutar cada um dos genes */
class BROperator::MUT : public oMutation {

    const char* name()const {
        return "BR-mut-30%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        BRCodification* codif = dynamic_cast<BRCodification*> (ind);
        for (int i = 0; i < 2; i++) {

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
        }

        if (codif->cromo[0] > 10.0)
            codif->cromo[0] = 10.0;
        else if (codif->cromo[0] < -5.0)
            codif->cromo[0] = -5.0;

        if (codif->cromo[1] > 15.0)
            codif->cromo[1] = 15.0;
        else if (codif->cromo[1] < 0.0)
            codif->cromo[1] = 0.0;

    };
};

Node* BROperator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
