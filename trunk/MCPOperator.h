/* 
 * File:   MCPOperator.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef MCPOPERATOR_H
#define	MCPOPERATOR_H

#include "Factory.h"

class MCPOperator : public Factory {
public:
    static const MCPOperator obj;
    MCPOperator();
    virtual ~MCPOperator();

    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* MCPOPERATOR_H */

