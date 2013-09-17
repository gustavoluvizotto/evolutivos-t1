/* 
 * File:   pObjective.h
 * Author: andre
 *
 * Created on 22 de Janeiro de 2013, 16:14
 */

#ifndef OBJECTIVE_H
#define	OBJECTIVE_H

#include "uException.h"

#include <string>
#include <ostream>

class Problem;
class Codification;
class Objective;
class StreamPrinter;
class LinkerResults;

using std::string;
using std::ostream;

class Objective {
public:
    Objective();
    virtual ~Objective();
    
    virtual void Start() throw(exception) = 0;
    
    virtual void Evaluate(Problem* mem, Codification* codif) throw(exception) = 0;
   
    virtual void Copy(Problem* mem, Objective* source) throw(exception) = 0;
        
    virtual Objective* New(Problem* mem) throw(exception) = 0;
        
    virtual double compareToAbs(const Objective* other) const = 0;
  
    virtual double compareToRel(const Objective* other) const = 0;
    
    virtual int compareTo(const Objective* other) const = 0;

    virtual void printer(Problem* mem, StreamPrinter* com) throw(exception) = 0;
    
    virtual void results(Problem* mem, LinkerResults* com) throw(exception) = 0;
    
    virtual void toString(ostream &out) throw(exception) = 0;
    
    virtual Objective* Clone(Problem* mem) throw(exception);
    
    virtual bool penalized() throw(exception);
private:

};

#endif	/* POBJECTIVE_H */

