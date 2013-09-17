/* 
 * File:   LocalMove.h
 * Author: marcio
 *
 * Created on 8 de Março de 2013, 21:42
 */

#ifndef LOCALMOVE_H
#define	LOCALMOVE_H

///#include "pMetaSolution.h"
//#include "oLocalMove.h"
#include<vector>
#include<exception>
using std::vector;
using std::exception;

class Problem;
class oLocalMove;
class Solution;

class LocalMove {
public:
    LocalMove(Problem* prob, vector<oLocalMove*>* moves);
    virtual ~LocalMove();
    Solution* local_search(Solution* ind) throw (exception);
private:
    Problem* prob;
    vector<oLocalMove*>* moves;
};

#endif	/* LOCALMOVE_H */

