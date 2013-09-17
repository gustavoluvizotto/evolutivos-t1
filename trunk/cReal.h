/* 
 * File:   cReal.h
 * Author: marcio
 *
 * Created on 11 de Junho de 2013, 17:44
 */

#ifndef CREAL_H
#define	CREAL_H

#include "Codification.h"
#include "oInitializer.h"
#include "oLocalMove.h"
#include "oCrossover.h"
#include "oMutation.h"

class cReal : public Codification{
public:
    cReal(int size);
    virtual ~cReal();

    virtual void Copy(Problem *prob, Codification *source) throw(exception);
    virtual Codification *New(Problem *prob) throw(exception);
    
    double X(int i);
    double X(int i, double a, double b);
    
    double* x;
    int length;
    
    
    //------------------- default operators ------------------
    class INIT;
    class CrossAvg;
    class CrossGeo;
    class CrossOnePoint;
    class CrossTwoPoint;
    class CrossOX;
    class CrossOXFast;
    class CrossBLX;
    class CrossHeur;
    class CrossLinear;
    class CrossAritm;
    class MutReplace;
    class MutLimit;
    class MutInvert;
    class MovReplace;
    class MovLimit;
    class MovInvert;
};

//------------------- default operators ------------------
class cReal::INIT : public oInitializer {
public:
    const char* name()const {
        return "Random";
    }
    const char* description() {
        return "para cada posição i do vetor pega-se a média dos valores dos pais nesta mesma posição";
    }
    void initialize(Problem* prob, Codification* B) throw (exception);
};

class cReal::CrossAvg : public oCrossover {
public:
    const char* name() const {
        return "Average";
    }
    const char* description() const {
        return "para cada posição i do vetor pega-se a média dos valores dos pais nesta mesma posição";
    }
    Codification* crossover(Problem* prob, Codification* A, Codification* B) throw (exception);
};

class cReal::CrossGeo : public oCrossover {
    const char* name() const {
        return "Geometric";
    }
    Codification* crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception);
};

class cReal::CrossOnePoint : public oCrossover {
    const char* name() const {
        return "One-point";
    }
    Codification* crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception);
};

class cReal::CrossTwoPoint : public oCrossover {
public:
    const char* name() const {
        return "Two-point";
    }
    Codification* crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception);
private:
    int points[2];
};

class cReal::CrossOX : public oCrossover {
    const char* name() const {
        return "OX";
    }
    Codification* crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception);
};

class cReal::CrossOXFast : public oCrossover {
public:
	CrossOXFast():mask(NULL){}
    const char* name() const {
        return "OX-Fast";
    }
    Codification* crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception);
private:
    long long* mask;
};

class cReal::CrossBLX : public oCrossover {
public:
    const char* name() const {
        return "BLX-a";
    }
    void parameters(LinkerParameters* win) throw (exception);
    Codification* crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception);
private:
    double alpha;
};

class cReal::CrossHeur : public oCrossover {
    const char* name() const {
        return "Heuristic";
    }
    Codification* crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception);
};

class cReal::CrossLinear : public oCrossover {
    const char* name() const {
        return "Linear";
    }
    Codification* crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception);
};

class cReal::CrossAritm : public oCrossover {
    const char* name() const {
        return "Aritmetic";
    }
    Codification* crossover(Problem* prob, Codification* A1, Codification* A2) throw (exception);
};

class cReal::MutReplace : public oMutation {
    const char* name() const {
        return "Replace";
    }
    void mutation(Problem* prob, Codification* A) throw (exception);
};

class cReal::MutLimit : public oMutation {
    const char* name() const {
        return "Limit";
    }
    void mutation(Problem* prob, Codification* A) throw (exception);
};

class cReal::MutInvert : public oMutation {
    const char* name() const {
        return "Invert";
    }
    void mutation(Problem* prob, Codification* A) throw (exception);
};


class cReal::MovReplace : public oLocalMove {
    const char* name() const {
        return "Replace";
    }
    void local_search(Problem* prob, Codification* A) throw (exception);
};

class cReal::MovLimit : public oLocalMove {
    const char* name() const {
        return "Limit";
    }
    void local_search(Problem* prob, Codification* A) throw (exception);
};

class cReal::MovInvert : public oLocalMove {
    const char* name() const {
        return "Invert";
    }
    void local_search(Problem* prob, Codification* A) throw (exception);
};


#endif	/* CREAL_H */

