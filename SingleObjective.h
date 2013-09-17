/* 
 * File:   pSingleObjective.h
 * Author: marcio
 *
 * Created on 8 de Abril de 2013, 16:51
 */

#ifndef SINGLEOBJECTIVE_H
#define	SINGLEOBJECTIVE_H

#include "Objective.h"

class BoundDbl;

class SingleObjective : public Objective{
public:
    SingleObjective();
    SingleObjective(const BoundDbl* bound);
    
    virtual ~SingleObjective();
    
    /**
     * @return the bound valid for the absolute value this objective 
     */
    const BoundDbl* Bound();
    /**
     * @return the absolute value cost this objective, interval [lb , ub]
     */
    double abs_value() const;
    /**
     * @return the relative cost this objective, interval [0 , 1]
     */
    double rel_value() const;
    /**
     * set the value this objective in absolute terms
     * interval [lb, ub]
     * @param value
     */
    void set(double value);
    
    
    
    virtual void Start() throw(exception);
    
    virtual void Evaluate(Problem* mem, Codification* codif) throw(exception) = 0;
   
    virtual Objective* New(Problem* mem) throw(exception) = 0;
    
    
    virtual void Copy(Problem* mem, Objective* source) throw(exception);
        
    virtual double compareToAbs(const Objective* other) const;
  
    virtual double compareToRel(const Objective* other) const;
    
    virtual int compareTo(const Objective* other) const;

    virtual void printer(Problem* mem, StreamPrinter* com) throw(exception);
    
    virtual void results(Problem* mem, LinkerResults* com) throw(exception);
    
    virtual void toString(ostream &out) throw(exception);
    //friend ostream& operator<< (ostream &out, pMetaSolution &sol);
    //virtual string toString() = 0;    
private:
    const BoundDbl* bound;
            
    double value;
};

#endif	/* PSINGLEOBJECTIVE_H */

