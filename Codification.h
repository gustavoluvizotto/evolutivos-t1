/* 
 * File:   pCodification.h
 * Author: andre
 *
 * Created on 22 de Janeiro de 2013, 16:15
 */

#ifndef CODIFICATION_H
#define	CODIFICATION_H

#include "uException.h"


class Problem;
class StreamPrinter;
class LinkerResults;

class Codification {
public:
    Codification();    
    virtual ~Codification();
    virtual void printer(Problem *prob, StreamPrinter *com) throw(exception);
    virtual void resulter(Problem *prob, LinkerResults *com) throw(exception);
    virtual void Copy(Problem *prob, Codification *source) throw(exception) = 0;
    virtual Codification *New(Problem *prob) throw(exception) = 0;
    Codification *Clone(Problem *prob) throw(exception);
private:

};

#endif	/* PCODIFICATION_H */

