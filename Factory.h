/* 
 * File:   FactoryService.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 17:02
 */

#ifndef FACTORY_H
#define	FACTORY_H

#include <string>

using std::string;

class Node;

class Factory{
public:
    Factory(){}
    virtual ~Factory(){}
    virtual const char* name()const = 0;
    virtual Node* NewService(int index)const = 0;
};





#define F_CLASS(Class, Obj)\
    class Node;\
    class Class : public Factory{\
    public:\
        static const Class obj;\
        Class();\
        virtual ~Class();\
        virtual const char* name()const;\
        virtual Node* NewService(int index)const;\
    };


#define F_INPL(Class, Obj, Name)\
const Class Class::obj;\
Class::Class() {\
}\
Class::~Class() {\
}\
const char* Class::name()const{\
    return Name;\
}\
Node* Class::NewService(int index)const\




#define OP_CLASS(Class, Operator, Name, Impl)\
    class Class : public Operator{\
    public:\
        const char* name()const{\
            return Name;\
        }\
        Impl\
    };


/* //Exemplo
 OP_CLASS(INIT,oInitializer,"Random",
    void initialize(pMetaProblem* prob, pCodification* B) throw(exception){
        cReal* ind = dynamic_cast<cReal*>(B);
        for(int i=0; i<ind->length; i++){
            ind->x[i] = prob->rmd->nextDouble();
        }
    })
 */


#endif	/* FACTORYSERVICE_H */

