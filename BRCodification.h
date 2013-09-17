/* 
 * File:   BRCodification.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef BRCODIFICATION_H
#define	BRCODIFICATION_H

#include "Codification.h"

class BRCodification : public Codification {
public:
    BRCodification();
    virtual ~BRCodification();

    virtual void Copy(Problem *prob, Codification *source) throw (exception);
    virtual Codification *New(Problem *prob) throw (exception);

    double * cromo;
private:

};

#endif	/* BRCODIFICATION_H */
