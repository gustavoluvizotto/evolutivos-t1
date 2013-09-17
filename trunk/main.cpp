
/*
 * File:   main.cpp
 * Author: marcio
 *
 * Created on 7 de Dezembro de 2012, 17:17
 */
#include "Problem.h"
#include "BestPareto.h"
#include "BoundInt.h"
#include "BoundDbl.h"
#include "pIteration.h"
#include "nEvaluations.h"
#include "aStop.h"
#include "MetaHeuristic.h"
#include "SaveSgl.h"
#include "dVertex.h"
#include "dNeed.h"
#include "dService.h"
#include "dFactory.h"
#include "Set.h"
#include "NodeParameter.h"
#include "NodeFactory.h"
#include "Run.h"
#include "NodeEnd.h"
#include "uException.h"
#include "StreamAdapter.h"
#include "StreamProgress.h"
#include "LinkerParameters.h"
#include "StreamPrinter.h"
#include "LinkerResults.h"
#include "Stream.h"
#include "LinkerValidations.h"
#include "Factory.h"
#include "Node.h"
#include "fRun.h"
#include "Model.h"
#include "Runner.h"
#include "BoundDbl.h"

#include <cstring>
#include <iostream>
using namespace std;


void client(int argc, char** argv);
void model();
void run(const char* job, const char* input);

/*
 *
 */
int main(int argc, char** argv) {
    //Client version
    client(argc, argv);

    //##### para testes do modelo descomente a linha abaixo ######
    //model();

    //##### para testes da execução descomente a linha abaixo ######
    run("E:\\0Aula\\ProOFClient\\work_space\\job\\finished\\utcz", "D:\\Dropbox\\ProOF\\ProOFClient\\work_space\\input");

    return 0;
}

void model(){
    printf("MODEL TEST\n");
    int argc = 2;
    char** argv = new char*[argc];
    argv[0] = strcpy(new char[10], "???");
    argv[1] = strcpy(new char[10], "model");
    client(argc, argv);
}
void run(const char* job, const char* input){
    printf("RUN TEST\n");
    int argc = 4;
    char** argv = new char*[argc];
    argv[0] = strcpy(new char[10], "???");
    argv[1] = strcpy(new char[10], "run");
    argv[2] = strcpy(new char[1000], job);
    argv[3] = strcpy(new char[1000], input);
    client(argc, argv);
}
void client(int argc, char** argv) {
    try {
        if (argc <= 1) {
            cerr << "no arguments" << endl;
            return;
        } else if (strcmp(argv[1], "model") == 0) {
            Model* model = new Model();
            model->create(&fRun::obj);
            model->savePof("model.pof");
            model->saveSgl("model.sgl");
        } else if (strcmp(argv[1], "run") == 0) {
            Runner* runner = new Runner(argv[2], argv[3], &fRun::obj);
            runner->run();
        } else {
            cerr << "arg[1]='" << argv[1] << "' is not recognized." << endl;
        }
        cout.flush();
        cerr.flush();
    } catch (exception& ex) {
        cerr << "------------ exception (...) ---------------" << endl;
        cerr << "ex:" << ex.what() << endl;
        cerr << "args:" << endl;
        for(int i=0; i<argc; i++){
            cerr << "\targ["<< i <<"]\t"<< argv[i] << endl;
        }
    } catch (...){
        cerr << "------------ exception (...) ---------------" << endl;
        cerr << "args:" << endl;
        for(int i=0; i<argc; i++){
            cerr << "\targ["<< i <<"]\t"<< argv[i] << endl;
        }
    }
    exit(EXIT_SUCCESS);
}

