/* 
 * File:   MRCodification.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef MRCODIFICATION_H
#define	MRCODIFICATION_H

#include "Codification.h"

class MRCodification : public Codification {
public:
    MRCodification();
    virtual ~MRCodification();

    virtual void Copy(Problem *prob, Codification *source) throw (exception);
    virtual Codification *New(Problem *prob) throw (exception);

    double * cromo;
private:

};

#endif	/* MRCODIFICATION_H */
