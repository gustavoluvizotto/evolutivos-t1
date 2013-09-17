/* 
 * File:   KLCodification.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef KLCODIFICATION_H
#define	KLCODIFICATION_H

#include "Codification.h"

class KLCodification : public Codification {
public:
    KLCodification();
    virtual ~KLCodification();

    virtual void Copy(Problem *prob, Codification *source) throw (exception);
    virtual Codification *New(Problem *prob) throw (exception);

    double * cromo;
private:

};

#endif	/* KLCODIFICATION_H */

