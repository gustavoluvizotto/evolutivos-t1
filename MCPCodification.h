/* 
 * File:   MCPCodification.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:18
 */

#ifndef MCPCODIFICATION_H
#define	MCPCODIFICATION_H

#include "Codification.h"

class MCPCodification : public Codification {
public:
    MCPCodification();
    virtual ~MCPCodification();

    virtual void Copy(Problem *prob, Codification *source) throw (exception);
    virtual Codification *New(Problem *prob) throw (exception);

    double * cromo;
private:

};

#endif	/* MCPCODIFICATION_H */

