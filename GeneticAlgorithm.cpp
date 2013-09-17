#include "GeneticAlgorithm.h"
#include "LinkerNodes.h"
#include "fProblem.h"
#include "Solution.h"
#include "Objective.h"
#include "LinkerParameters.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sys/time.h>
#include <vector>
#include <algorithm>

using namespace std;

/*Bubble sort*/
void GeneticAlgorithm::bubble(Solution** v, int qtd) {
    int i, j, k = qtd - 1;
    Solution* aux;

    for (i = 0; i < qtd; i++) {
        for (j = 0; j < k; j++) {
            if ((*v[j]) > (*v[j + 1])) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
        k--;
    }
}

int compara(const void*, const void*);

const char* GeneticAlgorithm::name()const {
    return "GA";
}

const char* GeneticAlgorithm::description()const {
    return NULL;
}

void GeneticAlgorithm::parameters(LinkerParameters *com) throw (exception) {
    numero_individuos = com->Int("numero de individuos", 10);
    numero_avaliacoes = com->Int("numero de avaliacoes", 100, 10, 1000000);
}

void GeneticAlgorithm::services(LinkerNodes *com) throw (exception) {
    problem = com->get(&fProblem::obj, problem);
    init = com->need(init);
    cross = com->need(cross);
    mut = com->need(mut);

}

void GeneticAlgorithm::execute() throw (exception) {
    timeval t1;
    gettimeofday(&t1, NULL);
    srand48(t1.tv_usec * t1.tv_sec);
    srand(time(NULL));

    int count_avaliacoes = 0;
    /*Alocação de memória*/
    best = problem->NewSolution();
//    Solution** matingPool = new Solution*[(int) numero_individuos / 2]; /*onde faremos os cruzamentos*/
    Solution** pop = new Solution*[numero_individuos];
//    vector<Solution*> pop;
    Solution** childPop = new Solution*[numero_individuos]; /*populacao dos filhos finais*/
    for (int i = 0; i < numero_individuos; i++) {
        pop[i] = problem->NewSolution();
        childPop[i] = problem->NewSolution();
    }
//    for (int i = 0; i < (int) numero_individuos / 2; i++)
//        matingPool[i] = problem->NewSolution();

    /*Inicia a população*/
    for (int i = 0; i < numero_individuos; i++) {
        init->initialize(problem, pop[i]);
    }

    /*Avalia a população*/
    for (int i = 0; i < numero_individuos; i++) {
        problem->evaluate(pop[i]);
        count_avaliacoes++;
        if (*(pop[i])<*best) {
            best->Copy(problem, pop[i]);
            cout << "best = ";
            best->toString(cout);
            cout << endl;
        }
    }
    //    cout << "imprimindo pop antes do bubble" << endl;
    //    for (int i = 0; i < numero_individuos; i++) {
    //        pop[i]->toString(cout);
    //        cout << endl;
    //    }
    //    cout << "terminou de imprimir antes do bubble " << endl;
    //    bubble(pop, numero_individuos);
    //    int melhores = 0.2 * numero_individuos - 1;
    //    int piores = 0.15 * numero_individuos - 1;
    //    int mid = piores;
    //    int gap = 0.25 * numero_individuos - 1;
    //
    //    for (int i = 0; i < melhores; i++)
    //        matingPool[i]->Copy(problem, pop[i]);
    //    for (int i = melhores + gap; i < melhores + mid + gap; i++)
    //        matingPool[i - gap]->Copy(problem, pop[i]);
    //    for (int i = melhores + mid + 2 * gap; i < numero_individuos; i++)
    //        matingPool[i - 2 * gap]->Copy(problem, pop[i]);
//    cout << "imprimindo pop apos bubble" << endl;
//    for (int i = 0; i < numero_individuos; i++) {
//        pop[i]->toString(cout);
//        cout << endl;
//    }
//    cout << "terminou de imprimir apos bubble" << endl;

    do {
        /*seleciona dois pais (Tournament Selection. Página 63 do livro do Eiben. )*/
        int p1 = tour(pop);
        int p2 = tour(pop);

        /*filho = crossover (pais). Gera 1 filho de cada 2 pais. */
        Solution* child = cross->crossover(problem, pop[p1], pop[p2]);
        /*mutaçao(filho)*/
        mut->mutation(problem, child);
        /*avaliar(filho)*/
        problem->evaluate(child);
        count_avaliacoes++;
        if (*(child)<*best) {
            best->Copy(problem, child);
            cout << "best = ";
            best->toString(cout);
            cout << endl;
        }
        /*insere na populacao*/
        int pior = *(pop[p1])>*(pop[p2]) ? p1 : p2;

        delete pop[pior];
        pop[pior] = child;
        //pop[pior]->Copy(problem, child);

    } while (count_avaliacoes < numero_avaliacoes);

    //    bubble(pop, numero_individuos);

    cout << "População final" << endl;
    for (int i = 0; i < numero_individuos; i++) {
        pop[i]->toString(cout);
        cout << endl;
    }
}

/* Tournament Selection. Seleciona 1 indivíduo da população, que
 * tem maior fitness, dentre 2 selecionados aleatoriamente. */
int GeneticAlgorithm::tour(Solution** pop) {
    //srand(time(NULL));
    int i = rand() % numero_individuos;
    int j = rand() % numero_individuos;

    if (*(pop[i])<*(pop[j])) {
        return i;
    } else {
        return j;
    }
}

void GeneticAlgorithm::results(LinkerResults *com) throw (exception) {
    best->objective->results(problem, com);
}

int compara(const void* p1, const void* p2) {
    if ((*(Solution*) p1) < (*(Solution*) p2))
        return 1;
    if ((*(Solution*) p1) == (*(Solution*) p2))
        return 0;
    if ((*(Solution*) p1) > (*(Solution*) p2))
        return -1;

}