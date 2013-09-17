/* 
 * File:   pBestSol.cpp
 * Author: andre
 * 
 * Created on 22 de Janeiro de 2013, 14:21
 */

#include "BestSol.h"

#include "nEvaluations.h"
#include "aStop.h"
#include "Solution.h"
#include "Problem.h"
#include "Objective.h"
#include "Codification.h"

#include "StreamPrinter.h"
#include "LinkerResults.h"
#include "LinkerNodes.h"

#include <time.h>

BestSol BestSol::obj;


BestSol::BestSol() {
    
}
BestSol::~BestSol() {
}
void BestSol::services(LinkerNodes *com) throw(exception){
    eval_tot    = com->add(&nEvaluations::obj);
    stop        = com->need(stop);
    problem     = com->need(problem);
}
double BestSol::time_now() {
    return (static_cast<double>(clock())-time_init)/(CLOCKS_PER_SEC);
}
double BestSol::time_best() {
    return time_best_;
}
double BestSol::time_after() {
    return time_now() - time_best_;
}
void BestSol::load() throw(exception) {
    //com = COM::mkPrinter("output of bests");
}
void BestSol::start() throw(exception){
    com = COM::mkPrinter("bests");
    best = problem->NewSolution();
    eval_best = 0;
    time_init = static_cast<double>(clock());
    time_best_ = 0;
}
void BestSol::results(LinkerResults *com) throw(exception) {
    com->writeLong("eval tot", eval_tot->value());
    com->writeLong("eval best", eval_best);
    com->writeDbl("time tot", time_now());
    com->writeDbl("time best", time_best());
    com->writeDbl("time after", time_after());
    best->objective->results(problem,com);
    best->codification->resulter(problem, com);
}

void BestSol::addBetter(Problem *mem, Solution *sol) throw(exception){
    eval_tot->update();
    
    if( !stop->end() && *sol < *best ) {
        best->Copy(mem, sol);
        eval_best = eval_tot->value();
        time_best_ = time_now();
        com->printLong("eval", eval_best);
        com->printDbl("time", time_best());
        best->objective->printer(mem, com);
        com->flush();
    }
}

