/* 
 * File:   HSKCodification.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef HSKCODIFICATION_H
#define	HSKCODIFICATION_H

#include "Codification.h"


class HSKCodification : public Codification {
public:
    HSKCodification();
    virtual ~HSKCodification();
    
    virtual void Copy(Problem *prob, Codification *source) throw(exception);
    virtual Codification *New(Problem *prob) throw(exception);
    
    double* cromo;
    
private:
    
};

#endif	/* HSKCODIFICATION_H */

