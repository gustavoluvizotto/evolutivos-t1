/* 
 * File:   WPOperator.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef WPOPERATOR_H
#define	WPOPERATOR_H

#include "Factory.h"

class WPOperator : public Factory {
public:
    static const WPOperator obj;
    WPOperator();
    virtual ~WPOperator();

    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* WPOPERATOR_H */
