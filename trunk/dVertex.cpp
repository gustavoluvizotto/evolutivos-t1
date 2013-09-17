/* 
 * File:   dVertex.cpp
 * Author: marcio
 * 
 * Created on 9 de Dezembro de 2012, 22:41
 */


#include "dVertex.h" 
#include "uException.h"
#include "Set.h"
#include "ComDefines.h"
#include "Run.h"
#include "NodeFactory.h"
#include "NodeSingle.h"
#include "NodeParameter.h"
#include "NodeEnd.h"
#include "Node.h"
#include "SaveSgl.h"
#include "dService.h"
#include "dFactory.h"
#include "dNeed.h"
#include "ComDefines.h"
#include "SavePof.h"

#include <typeinfo>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <iostream>


using std::type_info;
using std::vector;
using std::endl;
using std::iterator;
using std::string;

bool dVertex::operator==(const dVertex &obj) const
MEMBER
    RETURN this->set == obj.set;
END
void dVertex::add(Node* serv) 
MEMBER
    services.push_back(new dService<dVertex>(serv));
END
void dVertex::add(const char* type, const Factory* fact) 
MEMBER
    factorys.push_back(new dFactory<dVertex>('.', type, fact));
END
void dVertex::get(char signal, const char* type, const Factory* fact) 
MEMBER
    factorys.push_back(new dFactory<dVertex>(signal, type, fact));
END
int dVertex::getID() const
MEMBER
    RETURN set->getID();
END

void dVertex::update(const vector<dVertex*> &vertexes) throw (exception) 
MEMBER
    for(int v=0; v<vertexes.size(); v++){
	DEBUGF_2("update-b[%d]\n", v);
        for(int s=0; s<services.size(); s++){
            if(vertexes[v]->set->getID() == services[s]->getID()){
                services[s]->addVertex(vertexes[v]);
            }
        }
        if(vertexes[v]->set->fact()!=NULL){
            for(int f=0; f<factorys.size(); f++){
                if(vertexes[v]->set->fact() == factorys[f]->fact()){
                    factorys[f]->addVertex(vertexes[v]);
                }
            }
        }
	DEBUGF_2("end[%d]\n", v);
    }
END

void dVertex::addNeeds(dNeed* need) 
MEMBER
    needs.push_back(need);
END

void dVertex::mark_death() {
    if(!death){
        for(int n=0; n<needs.size(); n++){
            if(needs[n]->size()==0){
                death = true;
                return;
            }
        }
    }
}

void salvePof(ostream& output, dVertex *V) throw (exception) 
FUNCTION
    DEBUGF_1("Aqui!\n");

    string type =     instanceof(V->set->serv(), const Run*) ? "run" :
                      instanceof(V->set->serv(), const NodeFactory*   ) ? "factory":
                      instanceof(V->set->serv(), const NodeSingle*    ) ? "single":
                      instanceof(V->set->serv(), const NodeParameter* ) ? "param":
                      instanceof(V->set->serv(), const NodeEnd*       ) ? "end":
                      instanceof(V->set->serv(), const Node*   ) ? "serv":
                      "null";
    //output.printf("node [ id = %d, death = %s, type = %s, ref = '%s', name = '%s' ]{\n", set.serv.getID(), death, type, set.serv.getClass().getSuperclass().getSimpleName(), set.serv.name());
    output << "node [ id = " << V->set->getID() << ", death = " << V->death << ", type = " << type << ", ref = " << V->set->serv()->ref() << ", name = '" << V->set->name() << "' ]{" << endl;
    const vector<int> dads = V->set->get_dads();
    if(dads.size()>0){
        output << "\tdads{" << endl;
        output << "\t\t" << dads[0];
        for(int i=1; i<dads.size(); i++){
            output << "," << dads[i];
        }
        output << "\n\t}" << endl;        
    }
    if(V->services.size()>0){
        output << "\tservices{" << endl;
        output << "\t\t" << V->services[0]->getID();
        for(int s=1; s<V->services.size(); s++){
            output << "," << V->services[s]->getID();
        }
        output << "\n\t}" << endl;
    }
    if(V->factorys.size()>0){
        output << "\tfactorys{" <<endl;
        for(int f=0; f<V->factorys.size(); f++){
            output << "\t\t["<<V->factorys[f]->signal()<<"|"<<V->factorys[f]->type()<<"|"<<V->factorys[f]->fact()->name()<<"]{"<< V->factorys[f]->getID()<<"}"<< endl;
        }
        output << "\t}" << endl;
    }
    if(V->needs.size()>0){
        output<<"\tneeds{"<<endl;
        for(int n=0; n<V->needs.size(); n++){
            
            int index = 0;
            const char* aux = V->needs[n]->type();
            if(aux!=NULL && aux[index]=='P' && aux[index+1]>='0' && aux[index+1]<='9' ){
                index++;
                while(aux[index]>='0' && aux[index]<='9' ){
                    index++;
                }
            }
            
            const vector<dVertex*> vertexes = V->needs[n]->get();
            if(vertexes.size()==0){
                output << "\t\t[" << V->needs[n]->signal() << "|"<< &(aux[index]) << "]{death}" << endl;
            }else{
                //output.printf("\t\t"+"[%c|%s]{", n.signal, n.type.getSimpleName()); //n.type.getCanonicalName();
                output << "\t\t[" << V->needs[n]->signal() << "|"<< &(aux[index]) << "]{" << vertexes[0]->set->getID();
                for(int i=1; i<vertexes.size(); i++){
                    output << "," << vertexes[i]->set->getID();
                }
                output<<"}"<<endl;
            }
        }
        output << "\t}" << endl;
    }
    SavePof* win = new SavePof();
    V->set->serv()->parameters(win);
    if(win->size()>0){
        output<<"\tparameters{"<<endl;
        output<<win->str();
        output<<"\t}"<<endl;
    }
    output<<"}"<<endl;
    delete win;
END
void salveSgl(ostream& output, dVertex *V) throw (exception) 
FUNCTION
    int type =  instanceof(V->set->serv(), const Run*) ? 1 :
                instanceof(V->set->serv(), const NodeFactory*   ) ? 2 :
                instanceof(V->set->serv(), const NodeSingle*    ) ? 3 :
                instanceof(V->set->serv(), const NodeParameter* ) ? 4 :
                instanceof(V->set->serv(), const NodeEnd*       ) ? 5 :
                instanceof(V->set->serv(), const Node*   ) ? 0 :
                6;

    output<< "<node id>" << endl;
    output<< V->set->serv()->getID() << endl;
    output<< "<node death>" <<endl;
    output<< V->death << endl;
    output<< "<node type>" <<endl;
    output<< type << endl;
    output<< "<node ref>" <<endl;
    output<< V->set->serv()->ref() << endl;
    output<< "<node name>" << endl;
    output<< V->set->serv()->name() << endl;
    output<< "<services number>" <<endl;
    output<< V->services.size() << endl;
    if (V->services.size() > 0) {
        output<< "<services ..(id)>" << endl;
        for (int i=0; i<V->services.size(); i++) {
            if (V->services[i]->size() != 1) {
                throw uException("services[i].size()!=1");
            }
            output<< V->services[i]->getID() << endl;
        }
    }
    output << "<factorys number>" << endl;
    output << V->factorys.size() << endl;
    if (V->factorys.size() > 0) {
        //<factorys ..(signal:type:name:id)>
        output << "<factorys ..(signal:type:name:id)>" << endl;
        for (int f=0; f<V->factorys.size(); f++) {
            if (V->factorys[f]->size() != 1) {
                throw uException("factorys[f].size()!=1");
            }
            output<< V->factorys[f]->signal()<< ":" << V->factorys[f]->type()<< ":" << V->factorys[f]->name()<< ":" <<V->factorys[f]->getID() << endl;
        }
    }
    
    output << "<needs number>" << endl;
    output << V->needs.size() << endl;
    if (V->needs.size() > 0) {
        //<needs ..(signal:type:{..id})>
        output << "<needs ..(signal:type:{..id})>" << endl;
        for (int n = 0; n<V->needs.size(); n++) {
            //dNeed *N = (*V->needs)[n];
            int index = 0;
            const char* aux = V->needs[n]->type();
            if(aux!=NULL && aux[index]=='P' && aux[index+1]>='0' && aux[index+1]<='9' ){
                index++;
                while(aux[index]>='0' && aux[index]<='9' ){
                    index++;
                }
            }
            
            const vector<dVertex*> vertexes = V->needs[n]->get();
            if (vertexes.size() == 0) {
                output << V->needs[n]->signal() << ":"<< &(aux[index]) << ":" << "death" << endl;
            } else {
                output << V->needs[n]->signal() << ":"<< &(aux[index]) << ":" << vertexes[0]->getID();
                for(int v=1; v<vertexes.size(); v++){
                    output << "," << vertexes[v]->getID();
                }
                output << endl;
            }
        }
    }

    SaveSgl* win = new SaveSgl();
    V->set->serv()->parameters(win);
    output<< "<parameters number>" << endl;
    output<< win->size() << endl;
    if (win->size() > 0) {
        output << win->str();
    }
    delete win;
END

