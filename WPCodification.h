/* 
 * File:   WPCodification.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef WPCODIFICATION_H
#define	WPCODIFICATION_H

#include "Codification.h"

class WPCodification : public Codification {
public:
    WPCodification();
    virtual ~WPCodification();

    virtual void Copy(Problem *prob, Codification *source) throw (exception);
    virtual Codification *New(Problem *prob) throw (exception);

    double * cromo;
private:

};

#endif	/* WPCODIFICATION_H */
