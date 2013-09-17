/* 
 * File:   GRPCodification.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef GRPCODIFICATION_H
#define	GRPCODIFICATION_H

#include "Codification.h"


class GRPCodification : public Codification {
public:
    GRPCodification();
    virtual ~GRPCodification();
    
    virtual void Copy(Problem *prob, Codification *source) throw(exception);
    virtual Codification *New(Problem *prob) throw(exception);
    
    double * cromo;
private:
    
};

#endif	/* GRPCODIFICATION_H */

