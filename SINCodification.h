/* 
 * File:   SINCodification.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef SINCODIFICATION_H
#define	SINCODIFICATION_H

#include "Codification.h"

class SINCodification : public Codification {
public:
    SINCodification();
    virtual ~SINCodification();

    virtual void Copy(Problem *prob, Codification *source) throw (exception);
    virtual Codification *New(Problem *prob) throw (exception);

    int* cromo;

private:

};

#endif	/* SINCODIFICATION_H */
