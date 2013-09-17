/* 
 * File:   MROperator.h
 * Author: marcio
 *
 * Created on 30 de Agosto de 2013, 15:37
 */

#ifndef MROPERATOR_H
#define	MROPERATOR_H

#include "Factory.h"

class MROperator : public Factory {
public:
    static const MROperator obj;
    MROperator();
    virtual ~MROperator();

    virtual const char* name()const;
    virtual Node* NewService(int index)const;
private:
    class INIT;
    class CROSS;
    class MUT;
};

#endif	/* MROPERATOR_H */
