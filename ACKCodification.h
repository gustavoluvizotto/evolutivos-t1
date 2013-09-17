/* 
 * File:   ACKCodification.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef ACKCODIFICATION_H
#define	ACKCODIFICATION_H

#include "Codification.h"

class ACKCodification : public Codification {
public:
    ACKCodification();
    virtual ~ACKCodification();

    virtual void Copy(Problem *prob, Codification *source) throw (exception);
    virtual Codification *New(Problem *prob) throw (exception);

    double * cromo;
private:

};

#endif	/* ACKCODIFICATION_H */
