/* 
 * File:   ComProgressImpl.cpp
 * Author: marcio
 * 
 * Created on 16 de Dezembro de 2012, 15:24
 */

#include "StreamProgressImpl.h"
#include "ComDefines.h"
#include "uException.h"

StreamProgressImpl::StreamProgressImpl(const string& mk_name)
    : StreamProgress(COM::PROGRESS, mk_name), value(0) {}

StreamProgressImpl::~StreamProgressImpl() {
}

void StreamProgressImpl::restart() throw(exception){
    value = 0;
}

void StreamProgressImpl::progress(double p) throw (exception) {
    ASSERT(0<=p && p<=1 && p>=value);
    if(p-value>0.01){
        value = p;
        cout << COM::NAME << mk << COM::ARG << value << endl;
        #ifdef PRINT
            cout << "\t" << mk << " =  "<<value<< " ;" <<endl;
        #endif
    }
}


