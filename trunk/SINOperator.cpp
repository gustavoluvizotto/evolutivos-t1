/* 
 * File:   SINOperator.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "SINOperator.h"
#include "Problem.h"
#include "SINCodification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"
#include <sys/time.h>
#include <cstdlib>

const SINOperator SINOperator::obj;

SINOperator::SINOperator() {
}

SINOperator::~SINOperator() {
}

const char* SINOperator::name()const {
    return "SIN-Operator";
}

class SINOperator::INIT : public oInitializer {

    const char* name()const {
        return "SIN-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        SINCodification* codif = dynamic_cast<SINCodification*> (ind);

        timeval t1;
        gettimeofday(&t1, NULL);
        srand(t1.tv_usec * t1.tv_sec);

        for (int i = 0; i < 10; i++) {
            codif->cromo[i] = rand() % 2;
            cout << codif->cromo[i] << " ";
        }
        cout << endl;
    };
};

class SINOperator::CROSS : public oCrossover {

    const char* name()const {
        return "SIN-cross";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        SINCodification* codif1 = dynamic_cast<SINCodification*> (ind1);
        SINCodification* codif2 = dynamic_cast<SINCodification*> (ind2);
        SINCodification* child = dynamic_cast<SINCodification*> (codif1->New(prob));

        timeval t1;
        gettimeofday(&t1, NULL);
        srand(t1.tv_usec * t1.tv_sec);

        for (int i = 0; i < 10; i++) {
            child->cromo[i] = rand() % 2 ? codif1->cromo[i] : codif2->cromo[i];
        }
        return child;
    };
};

class SINOperator::MUT : public oMutation {

    const char* name()const {
        return "SIN-mut";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        SINCodification* codif = dynamic_cast<SINCodification*> (ind);

        timeval t1;
        gettimeofday(&t1, NULL);
        srand(t1.tv_usec * t1.tv_sec);

        int i = rand() % 10;
        codif->cromo[i] = 1 - codif->cromo[i];
    };
};

Node* SINOperator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
