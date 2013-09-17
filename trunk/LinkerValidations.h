/* 
 * File:   ComValidation.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 18:29
 */

#ifndef LINKERVALIDATIONS_H
#define	LINKERVALIDATIONS_H

#include <string>

using std::string;

class LinkerValidations {
public:
    virtual ~LinkerValidations(){}
    virtual void error(string& name);
    virtual void warning(string& name);
    virtual void error(int index);
    virtual void warning(int index);
};

#endif	/* COMVALIDATION_H */

