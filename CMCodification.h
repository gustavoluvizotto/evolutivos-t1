/* 
 * File:   CMCodification.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef CMCODIFICATION_H
#define	CMCODIFICATION_H

#include "Codification.h"


class CMCodification : public Codification {
public:
    CMCodification();
    virtual ~CMCodification();
    
    virtual void Copy(Problem *prob, Codification *source) throw(exception);
    virtual Codification *New(Problem *prob) throw(exception);
    
    double * cromo;
private:
    
};

#endif	/* CMCODIFICATION_H */

