/* 
 * File:   SINU20Codification.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef SINU20CODIFICATION_H
#define	SINU20CODIFICATION_H

#include "Codification.h"

class SINU20Codification : public Codification {
public:
    SINU20Codification();
    virtual ~SINU20Codification();

    virtual void Copy(Problem *prob, Codification *source) throw (exception);
    virtual Codification *New(Problem *prob) throw (exception);

    double * cromo;
private:

};

#endif	/* SINU20CODIFICATION_H */
