/* 
 * File:   HVCodification.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef HVCODIFICATION_H
#define	HVCODIFICATION_H

#include "Codification.h"


class HVCodification : public Codification {
public:
    HVCodification();
    virtual ~HVCodification();
    
    virtual void Copy(Problem *prob, Codification *source) throw(exception);
    virtual Codification *New(Problem *prob) throw(exception);
    
    double* cromo;
    
private:
    
};

#endif	/* HVCODIFICATION_H */

