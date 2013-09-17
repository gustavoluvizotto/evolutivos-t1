/* 
 * File:   H6Codification.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef H6CODIFICATION_H
#define	H6CODIFICATION_H

#include "Codification.h"


class H6Codification : public Codification {
public:
    H6Codification();
    virtual ~H6Codification();
    
    virtual void Copy(Problem *prob, Codification *source) throw(exception);
    virtual Codification *New(Problem *prob) throw(exception);
    
    double * cromo;
private:
    
};

#endif	/* H6CODIFICATION_H */

