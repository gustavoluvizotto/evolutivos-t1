/* 
 * File:   MetaProblemFactory.cpp
 * Author: marcio
 * 
 * Created on 8 de Março de 2013, 22:28
 */

#include "fProblem.h"
#include "FUNProblem.h"
#include "SINProblem.h"
#include "ACKProblem.h"
#include "HSKProblem.h"
#include "HVProblem.h"
#include "KLProblem.h"
#include "LM2Problem.h"
#include "MCPProblem.h"
#include "MRProblem.h"
#include "SINU20Problem.h"
#include "WPProblem.h"
#include "BRProblem.h"
#include "CMProblem.h"
#include "EXPProblem.h"
#include "GPProblem.h"
#include "GRPProblem.h"
#include "H6Problem.h"

const fProblem fProblem::obj;

fProblem::fProblem() {
}

fProblem::~fProblem() {
}

const char* fProblem::name()const {
    return "Problem";
}

Node* fProblem::NewService(int index)const {
    switch (index) {

        case 0: return new ACKProblem();
        case 1: return new CMProblem();
        case 2: return new EXPProblem();
        case 3: return new GPProblem();
        case 4: return new GRPProblem();
        case 5: return new H6Problem();
        case 6: return new HSKProblem();
        case 7: return new HVProblem();
        case 8: return new KLProblem();
        case 9: return new LM2Problem();
        case 10: return new MCPProblem();
        case 11: return new MRProblem();
        case 12: return new BRProblem();
        case 13: return new SINU20Problem();
        case 14: return new WPProblem();

            //exemplos
        case 15: return new FUNProblem();
        case 16: return new SINProblem();
    }
    return NULL;
}
