/* 
 * File:   LM2Codification.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef LM2CODIFICATION_H
#define	LM2CODIFICATION_H

#include "Codification.h"


class LM2Codification : public Codification {
public:
    LM2Codification();
    virtual ~LM2Codification();
    
    virtual void Copy(Problem *prob, Codification *source) throw(exception);
    virtual Codification *New(Problem *prob) throw(exception);
    
    double* cromo;
    
private:
    
};

#endif	/* LM2CODIFICATION_H */

