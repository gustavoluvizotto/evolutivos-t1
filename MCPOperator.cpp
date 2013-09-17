/* 
 * File:   MCPOperator.cpp
 * Author: marcio
 * 
 * Created on 30 de Agosto de 2013, 15:37
 */

#include "MCPOperator.h"
#include "Problem.h"
#include "MCPCodification.h"
#include "oCrossover.h"
#include "oMutation.h"
#include "oInitializer.h"

#include <cstdlib>

const MCPOperator MCPOperator::obj;

MCPOperator::MCPOperator() {
}

MCPOperator::~MCPOperator() {
}

const char* MCPOperator::name()const {
    return "MCP-Operator";
}

/* inicializa 1 cromossomo com 4 genes, com valores double entre -1 e 1 */
class MCPOperator::INIT : public oInitializer {

    const char* name()const {
        return "MCP-init";
    }

    void initialize(Problem* prob, Codification* ind) throw (exception) {
        MCPCodification* codif = dynamic_cast<MCPCodification*> (ind);
        
        srand(time(NULL));
        for (int i = 0; i < 4; i++)
            codif->cromo[i] = drand48()*2.0 - 1.0;
    };
};

class MCPOperator::CROSS : public oCrossover {

    const char* name()const {
        return "MCP-cross-MediaAritmetica";
    }

    Codification* crossover(Problem* prob, Codification* ind1, Codification* ind2) throw (exception) {
        MCPCodification* codif1 = dynamic_cast<MCPCodification*> (ind1);
        MCPCodification* codif2 = dynamic_cast<MCPCodification*> (ind2);
        MCPCodification* child = dynamic_cast<MCPCodification*> (codif1->New(prob));
        
        for (int i = 0; i < 4; i++)
            child->cromo[i] = (codif1->cromo[i] + codif2->cromo[i]) / 2.0; //crossover média aritmética
        return child;
    };
};

/* 30% de chance de mutar cada um dos 4 genes de 1 cromossomo */
class MCPOperator::MUT : public oMutation {

    const char* name()const {
        return "MCP-mut-30%";
    }

    void mutation(Problem* prob, Codification* ind) throw (exception) {
        MCPCodification* codif = dynamic_cast<MCPCodification*> (ind);
        for (int i = 0; i < 4; i++) {
            srand(time(NULL));
            bool muta = drand48() < 0.25; //chance de realizar mutação
            double porcentagem_mutacao = drand48() * 0.3; //se realizar mutação, essa é a taxa

            if (muta) {
                if (drand48() < 0.5) //mutar para cima ou para baixo
                    codif->cromo[i] = (1 + porcentagem_mutacao) * codif->cromo[i];
                else
                    codif->cromo[i] = (1 - porcentagem_mutacao) * codif->cromo[i];
            }
            if (codif->cromo[i] > 1.0)
                codif->cromo[i] = 1.0;
            if (codif->cromo[i] < -1.0)
                codif->cromo[i] = -1.0;
        }
    };
};

Node* MCPOperator::NewService(int index)const {
    switch (index) {
        case 0: return new INIT();
        case 1: return new CROSS();
        case 2: return new MUT();
    }
    return NULL;
}
