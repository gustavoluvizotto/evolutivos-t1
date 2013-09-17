/* 
 * File:   FUNCodification.h
 * Author: marcio
 *
 * Created on 29 de Agosto de 2013, 16:57
 */

#ifndef FUNCODIFICATION_H
#define	FUNCODIFICATION_H

#include "Codification.h"

class FUNCodification : public Codification{
public:
    FUNCodification(Problem* prob);
    virtual ~FUNCodification();
    virtual void Copy(Problem *prob, Codification *source) throw(exception);
    virtual Codification *New(Problem *prob) throw(exception);
    
    double x;
private:
    
};

#endif	/* FUNCODIFICATION_H */

