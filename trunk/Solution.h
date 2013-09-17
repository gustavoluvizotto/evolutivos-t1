/* 
 * File:   pMetaSolution.h
 * Author: andre
 *
 * Created on 22 de Janeiro de 2013, 14:06
 */

#ifndef SOLUTION_H
#define	SOLUTION_H
#include "uException.h"
#include <ostream>

using std::ostream;

class Problem;
class Objective;
class Codification;
class Solution;

class Solution {
    
public:

    Solution(Objective *objective, Codification *codification) throw (exception);

    Solution(Problem *mem) throw (exception);

    virtual ~Solution();
    
    virtual Solution* New(Problem *mem) throw (exception);
    
    virtual Solution* New(Problem *mem, Codification *codification) throw (exception);

    void Evaluate(Problem *mem) throw (exception);
    bool penalized() throw (exception);

    double compareToAbs(const Solution *other) const;

    double compareToRel(const Solution *other) const;

    Codification *codif();

    Solution *minimum( Solution *other);

    friend bool operator<=(const Solution &a, const Solution &b);
    friend bool operator< (const Solution &a, const Solution &b);
    friend bool operator==(const Solution &a, const Solution &b);
    friend bool operator> (const Solution &a, const Solution &b);
    friend bool operator>=(const Solution &a, const Solution &b);

    int compareTo(const Solution *other) const;

    void toString(ostream &out);

    void Copy(Problem *mem, Solution *source) throw(exception);
    Solution* Clone(Problem *mem) throw (exception);
    
    
    Objective *objective;
    Codification *codification;
private:
    
};

#endif	/* PMETASOLUTION_H */

