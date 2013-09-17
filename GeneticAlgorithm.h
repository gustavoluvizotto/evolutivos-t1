#ifndef GENETICALGORITHM_H
#define	GENETICALGORITHM_H

#include "MetaHeuristic.h"
#include "Problem.h"
#include "oInitializer.h"
#include "oCrossover.h"
#include "oMutation.h"

class GeneticAlgorithm : public MetaHeuristic {
public:

    GeneticAlgorithm() {
    }

    virtual ~GeneticAlgorithm() {
    }

    virtual const char* name()const;
    virtual const char* description()const;
    virtual void parameters(LinkerParameters *com) throw (exception);
    virtual void services(LinkerNodes *com) throw (exception);
    virtual void execute() throw (exception);
    virtual void results(LinkerResults *com) throw (exception);
    void bubble(Solution** v, int qtd);
private:
    int numero_individuos;
    int numero_avaliacoes;
    Problem* problem;
    
    oInitializer* init;
    oCrossover* cross;
    oMutation* mut;

    Solution* best;

    int tour(Solution** pop);
};

#endif
