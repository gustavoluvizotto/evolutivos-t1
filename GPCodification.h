/* 
 * File:   GPCodification.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef GPCODIFICATION_H
#define	GPCODIFICATION_H

#include "Codification.h"


class GPCodification : public Codification {
public:
    GPCodification();
    virtual ~GPCodification();
    
    virtual void Copy(Problem *prob, Codification *source) throw(exception);
    virtual Codification *New(Problem *prob) throw(exception);
    
    double * cromo;
private:
    
};

#endif	/* GPCODIFICATION_H */

