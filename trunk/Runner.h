/* 
 * File:   Runner.h
 * Author: marcio
 *
 * Created on 14 de Dezembro de 2012, 22:28
 */

#ifndef RUNNER_H
#define	RUNNER_H

#include "uException.h"
#include "fRun.h"
#include "Fact.h"
#include "Serv.h"
#include "Node2.h"

#include <vector>
class Run;

using std::vector;

class Runner {
public:
    Runner(const char* task, const char* input, const fRun* obj) throw(exception);
    virtual ~Runner();
    
    void run() throw(exception);
    
    static void find(vector<Fact*>& rtn, const vector<Fact*>& sets, const Factory* fact);
    static Node2* find(const vector<Node2*>& all, const Serv* serv);
private:
    vector<Fact*> sets;
    vector<Serv*> servs;
    vector<Node2*> nodes;
    Run* exec;
};

#endif	/* RUNNER_H */

