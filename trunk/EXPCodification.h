/* 
 * File:   EXPCodification.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef EXPCODIFICATION_H
#define	EXPCODIFICATION_H

#include "Codification.h"


class EXPCodification : public Codification {
public:
    EXPCodification();
    virtual ~EXPCodification();
    
    virtual void Copy(Problem *prob, Codification *source) throw(exception);
    virtual Codification *New(Problem *prob) throw(exception);
    
    double * cromo;
private:
    
};

#endif	/* EXPCODIFICATION_H */

