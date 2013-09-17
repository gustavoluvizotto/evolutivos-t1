/* 
 * File:   cIteration.h
 * Author: andre
 *
 * Created on 13 de Dezembro de 2012, 20:21
 */

#ifndef PITERATION_H
#define	PITERATION_H

#include <exception>
#include "NodeSingle.h"
#include "pIteration.h"
#include "LinkerResults.h"

class pIteration: public NodeSingle{
public:
    static pIteration obj;
    pIteration();
    virtual ~pIteration();
    void iteration(){iterations++;}
    long value(){return iterations;}
    
    const char* name()const {return "Iterations";}
    
    const char* description()const {return NULL;}
    
    void start() throw(exception){iterations = 0;}
    void results(LinkerResults *com) throw(exception){
        com->writeInt("iterations", iterations);
    }
private:    
//    public static cIteration object(){
//        if(obj==null){
//            obj = new cIteration();
//        }
//        return obj;
//    }


    //cIteration() {}    
    long iterations;
        
};

#endif	/* CITERATION_H */

