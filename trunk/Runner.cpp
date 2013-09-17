/* 
 * File:   Runner.cpp
 * Author: marcio
 * 
 * Created on 14 de Dezembro de 2012, 22:28
 */

#include "Runner.h"
#include "ComDefines.h"
#include "uException.h"
#include "WinServices.h"
#include "WinParams.h"
#include "WinNeeds.h"
#include "LinkerNodes.h"
#include "Run.h"

#include <fstream>
#include <sstream>
#include <string.h>
using std::ifstream;
using std::ostringstream;


//------------------------------PRINT DEFINES BEGIN-----------------------------
#define RUNNER_PRINT_LINK(MSG)\
    printf(MSG);\
    for(int n=0; n<nodes.size(); n++){\
        printf("%s\n",nodes[n]->name());\
        for(int s=0; nodes[n]->facts.size(); s++){\
            printf("\t%s\n",nodes[n]->facts[s]->name());\
        }\
    }\
    printf("----------------------------------");


#define RUNNER_PRINT_NODE(index)\
    printf("%s\n", nodes[index]->name().c_str());\
    if(nodes[index]->facts.size()>0){\
        printf("\t%s\n", "factorys");\
        for(int s=0; s<nodes[index]->facts.size(); s++){\
            printf("\t\t%s\n",nodes[index]->facts[s]->name());\
        }\
    }\
    if(nodes[index]->needs.size()>0){\
        printf("\t%s\n", "needs");\
        for(int l=0; l<nodes[index]->needs.size(); l++){\
            vector<Node*>* list = nodes[index]->needs[l];\
            if(list->size()>0){\
                cout << "\t\t[ " << (*list)[0]->name();\
                for(int k=1; k<list->size(); k++){\
                    cout << " " << (*list)[k]->name() << endl;\
                }\
                cout << " ] " << endl;\
            }else{\
                cout << "\t\t[ ] " << endl;\
            }\
        }\
    }

//------------------------------PRINT DEFINES END-------------------------------

Runner::Runner(const char* task, const char* input, const fRun* obj) throw(exception) {
    PRINTF_1("-------------[Runner constructor]--------------\n");
    int n_facts, n_servs;
    
    ifstream scanner(task, ifstream::in);
    
    if(!scanner){
        ostringstream msg;
        msg << "error = task '"<<task<<"' can not be open";
        throw uException(msg.str());
    }
    
    
    NEXT_TRASH(scanner);
    NEXT_INT(scanner, n_facts);
    
    for(int f=0; f<n_facts; f++){
        sets.push_back(new Fact(scanner));
    }
    
    if(n_facts<1 || sets[0]->chooses.size()!=1){
        ostringstream out;
        out << "Factory '" << sets[0]->name() << "' chooses = " << sets[0]->chooses.size() << " != 1";
        throw uException(out.str());
    }
    
    NEXT_TRASH(scanner);
    NEXT_INT(scanner, n_servs);
    for(int s=0; s<n_servs; s++){
        servs.push_back(new Serv(scanner));
    }
    scanner.close();
    
    PRINTF_1("-------------[exec node]--------------\n");
    exec = dynamic_cast<Run*>(obj->NewService(sets[0]->chooses[0]));
    PRINTF_2("exec : %s\n", exec->name());
    
    
    WinServices* winA = new WinServices(exec);
    LinkerNodes* comA = new LinkerNodes(winA, NULL, NULL);
    

    PRINTF_1("-----------[link factorys]------------\n");
    while(winA->n_servs()>0){
        Node* serv = winA->nextServ();
        Node2* node = new Node2(serv);
        PRINTF_2("serveces : %s\n", serv->name());
        serv->services(comA);
        while(winA->n_facts()>0){
            const Factory* fact = winA->nextFact();
            vector<Fact*> rtn;
            find(rtn, sets, fact);
            
            if(rtn.size()==0){
                ostringstream out;
                out << "Factory '" << fact->name() << "' not found";
                throw uException(out.str());
            }else{
                for(int i=0; i<rtn.size(); i++){
                    Fact* f = rtn[i];
                    for(int c=0; c<f->chooses.size(); c++){
                        Node *s = fact->NewService(f->chooses[c]);
                        if(s==NULL){
                            ostringstream out;
                            out << "Factory '" << fact->name() << "'  NewService("<<f->chooses[c]<<")==null";
                            throw uException(out.str());
                        }
                        s->construct();
                        winA->add(s);
                        node->add(s);
                    }
                }
            }
        }
        nodes.push_back(node);
    }
    
    #ifdef PRINT
        //RUNNER_PRINT_LINK("-------------[after link]--------------\n");
        printf("-------------[after link]--------------\n");
        for(int n=0; n<nodes.size(); n++){
            Node2* no = nodes[n];
            printf("%s\n",no->name().c_str());
            for(int s=0; s<no->facts.size(); s++){
                Node* serv = no->facts[s];
                printf("\t%s\n",serv->name());
            }
        }
        printf("----------------------------------\n");
    #endif

    PRINTF_1("-------------[read params]-------------\n");
    WinParams* winc = new WinParams(input);
    for(int s=0; s<servs.size(); s++){
        Node2* no = find(nodes, servs[s]);
        if(no==NULL){
            ostringstream out;
            out << "Not find service '" << servs[s]->name().c_str() << "'";
            throw uException(out.str());
        }
        winc->start(servs[s]);
        no->serv->parameters(winc);
    }
    
    
    PRINTF_1("-------------[link needs]--------------\n");
    WinNeeds* winb = new WinNeeds(&nodes);
    LinkerNodes* comB = new LinkerNodes(NULL,NULL, winb);
    for(int n=0; n<nodes.size(); n++){
        winb->start(nodes[n]);
        nodes[n]->serv->services(comB);
        #ifdef PRINT
            RUNNER_PRINT_NODE(n);
        #endif
    }
}

Runner::~Runner() {
}

void Runner::run() throw(exception) {
    PRINTF_1("-------------[loading]--------------\n");
    for(int n=0; n<nodes.size(); n++){
        PRINTF_2("%s\n", nodes[n]->name().c_str());
        nodes[n]->serv->load();
    }
    PRINTF_1("------------[starting]--------------\n");
    for(int n=0; n<nodes.size(); n++){
        PRINTF_2("%s\n", nodes[n]->name().c_str());
        nodes[n]->serv->start();
    }
    PRINTF_1("------------[executing]-------------\n");
    PRINTF_2("%s\n", exec->name());
    exec->execute();

    PRINTF_1("-------------[results]--------------\n");
    LinkerResults* com = COM::results();
    for(int n=0; n<nodes.size(); n++){
        PRINTF_3("node[%d] = %s\n", n, nodes[n]->name().c_str());
        nodes[n]->serv->results(com);
        PRINTF_1("end\n");
    }
    PRINTF_1("--------------[close]---------------\n"); 
    
    
    PRINTF_1("---------------[end]----------------\n");
}

void Runner::find(vector<Fact*>& rtn, const vector<Fact*>& sets, const Factory* fact){
    //PRINTF_2("\tfind %s ", fact->name().c_str());
    rtn.clear();
    for(int f=0; f<sets.size(); f++){
        //if(sets[f]->name()==fact->name()){
        //PRINTF_4("find %s == %s -> %d\n", fact->name().c_str(), sets[f]->name().c_str(), sets[f]->name().compare(fact->name()));
        if(sets[f]->name().compare(fact->name())==0){
            //PRINTF_2("-> %s\n", fact->name().c_str());
            rtn.push_back(sets[f]);
        }
    }
}
/*Fact* Runner::find(const vector<Fact*>& sets, const FactoryService* fact){
    //PRINTF_2("\tfind %s ", fact->name().c_str());
    for(int f=0; f<sets.size(); f++){
        //if(sets[f]->name()==fact->name()){
        //PRINTF_4("find %s == %s -> %d\n", fact->name().c_str(), sets[f]->name().c_str(), sets[f]->name().compare(fact->name()));
        if(sets[f]->name().compare(fact->name())==0){
            //PRINTF_2("-> %s\n", fact->name().c_str());
            return sets[f];
        }
    }
    return NULL;
}*/
Node2* Runner::find(const vector<Node2*>& all, const Serv* serv){
    //PRINTF_3("find-2 %d %s\n", all.size(), serv->name().c_str());
    for(int n=0; n<all.size(); n++){
        //if(all[n]->name()==serv->name()){
        //PRINTF_4("find %s == %s -> %d\n", serv->name().c_str(), all[n]->name().c_str(), all[n]->name().compare(serv->name()));
        if(all[n]->name().compare(serv->name())==0){
            return all[n];
        }
    }
    return NULL;
}

