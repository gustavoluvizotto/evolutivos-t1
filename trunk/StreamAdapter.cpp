/* 
 * File:   ComStreamAdapter.cpp
 * Author: marcio
 * 
 * Created on 9 de Dezembro de 2012, 19:46
 */
#include "StreamAdapter.h"
#include "uException.h"
#include "ComDefines.h"

StreamAdapter::StreamAdapter(const string& type, const string& name)
        : t(type), mk(name), isOpen(false)
{
    open();
};
StreamAdapter::~StreamAdapter(){
    
}
const string& StreamAdapter::type()const throw (exception) {
    return t;
}
const string& StreamAdapter::name()const throw (exception) {
    return mk;
}
void StreamAdapter::open() throw (exception) {
    if (isOpen) {
        string s("aa");
        throw uException("'" + s + "' already open");
    } else {
        cout << COM::NAME << COM::OPEN << COM::ARG << t << COM::ARG << mk << endl;
        isOpen = true;
    }
}
void StreamAdapter::flush() throw(exception){
    
}
void StreamAdapter::close() throw (exception) {
    if (isOpen) {
        cout << COM::NAME << COM::CLOSE << COM::ARG << mk << endl;
        isOpen = false;
    } else {
        throw uException("'" + name() + "' already close");
    }
}

