/* 
 * File:   FUNOperator.cpp
 * Author: marcio
 * 
 * Created on 29 de Agosto de 2013, 17:02
 */

#include "FUNOperator.h"

#include "oInitializer.h"
#include "oMutation.h"
#include "oCrossover.h"

#include <cstddef>
#include <cstdlib>

#include "ComDefines.h"
#include "FUNCodification.h"

const FUNOperator FUNOperator::obj;

FUNOperator::FUNOperator() {
}

FUNOperator::~FUNOperator() {
}

const char* FUNOperator::name()const{
    return "FUN-Operators";
}

class FUNOperator::INIT : public oInitializer{
public:    
    const char* name()const{
        return "Init-x";
    }
    void initialize(Problem* A, Codification* B) throw(exception){ 
        FUNCodification* ind = dynamic_cast<FUNCodification*>(B);
        ind->x = rand();
    }
};

class FUNOperator::MUT : public oMutation{
public:    
    const char* name()const{
        return "Mut-x";
    }
    void mutation(Problem* A, Codification* B) throw(exception){
        FUNCodification* ind = dynamic_cast<FUNCodification*>(B);
        ind->x += (rand()%10-5);
    }
};
class FUNOperator::CROSS : public oCrossover{
public:
    const char* name()const{
        return "Cross-x";
    }
    Codification* crossover(Problem* A, Codification* B, Codification* C) throw(exception){
        FUNCodification* ind1 = dynamic_cast<FUNCodification*>(B);
        FUNCodification* ind2 = dynamic_cast<FUNCodification*>(C);
        FUNCodification* child = dynamic_cast<FUNCodification*>(ind1->New(A));
        child->x = (ind1->x + ind2->x) / 2;
        return child;
    }
};

Node* FUNOperator::NewService(int index)const{
    switch(index){
        case 0: return new FUNOperator::INIT();
        case 1: return new FUNOperator::CROSS();
        case 2: return new FUNOperator::MUT();
    }
    return NULL;
}

