/* 
 * File:   ComProgressImpl.h
 * Author: marcio
 *
 * Created on 16 de Dezembro de 2012, 15:24
 */

#ifndef STREAMPROGRESSIMPL_H
#define	STREAMPROGRESSIMPL_H

#include "StreamProgress.h"

class StreamProgressImpl: public StreamProgress {
public:
    StreamProgressImpl(const string& mk_name);
    virtual ~StreamProgressImpl();
    virtual void progress(double value) throw(exception);
    virtual void restart() throw(exception);
private:
    double value;
};

#endif	/* COMPROGRESSIMPL_H */

