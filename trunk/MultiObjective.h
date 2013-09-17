/* 
 * File:   pMultiObjective.h
 * Author: marcio
 *
 * Created on 11 de Junho de 2013, 16:02
 */

#ifndef MULTIOBJECTIVE_H
#define	MULTIOBJECTIVE_H

#include "Objective.h"

class BoundDbl;

class MultiObjective : public Objective{
public:
    MultiObjective(int goals, const BoundDbl** bound);
    
    virtual ~MultiObjective();
    
    /**
     * @return the number of goals this objective function 
     */
    int goals();
    
    /**
     * @return the bound valid for the absolute value this objective 
     */
    const BoundDbl* Bound(int i);
    
    /**
     * @return the absolute value cost this objective, interval [lb , ub]
     */
    double abs_value(int i) const;
    /**
     * @return the relative cost this objective, interval [0 , 1]
     */
    double rel_value(int i) const;
    /**
     * set the value this objective in absolute terms
     * interval [lb, ub]
     * @param value
     */
    void set(int i, double value);
    
    
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
    
    int compareTo(int i, const MultiObjective* other) const;
private:
    const BoundDbl** bounds;
    int g;              //goals
    double* values;
};

#endif	/* PMULTIOBJECTIVE_H */

