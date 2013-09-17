/* 
 * File:   H6Operator.h
 * Author: beatriz
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef H6OPERATOR_H
#define	H6OPERATOR_H

#include "Factory.h"

class H6Operator : public Factory{
public:
    static const H6Operator obj;
    H6Operator();
    virtual ~H6Operator();
    
    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* H6OPERATOR_H */

