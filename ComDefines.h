/* 
 * File:   ComDefines.h
 * Author: marcio
 *
 * Created on 14 de Dezembro de 2012, 20:30
 */

#ifndef COMDEFINES_H
#define	COMDEFINES_H

#include <string>
#include "StreamPrinter.h"
#include "StreamProgress.h"
#include "LinkerResults.h"

using std::string;

namespace Integer{
    /** -2147483648*/
    const int MIN_VALUE = 0x80000000;
    /**  2147483647*/
    const int MAX_VALUE = 0x7fffffff;
}
namespace Long{
    /** -9223372036854775808*/
    //const long long MIN_VALUE = 0x8000000000000000L;
	const long long MIN_VALUE = 0x80000000;
    /** +9223372036854775807*/
    //const long long MAX_VALUE = 0x7fffffffffffffffL;
	const long long MAX_VALUE = 0x7fffffff;
}
namespace Double{
    /** 4.9e-324*/
    const double MIN_VALUE = 0x0.0000000000001P-1022;   
    /** 1.7976931348623157e+308*/
    const double MAX_VALUE = 0x1.fffffffffffffP+1023;
    /** 2.2250738585072014E-308*/
    const double MIN_NORMAL = 0x1.0p-1022;              
}

namespace COM{
    extern const string NAME;
    extern const string ARG;
    
    extern const string INT;
    extern const string LONG;
    extern const string DOUBLE;
    extern const string STRING;
    
    extern const string RESULTS;
    extern const string PROGRESS;
    extern const string STREAM;
    extern const string WRITE;
    
    extern const string OPEN;
    extern const string CLOSE;
    extern const string OUTPUT;
    extern const string ERROR;
    
    
    extern StreamPrinter* mkPrinter(const string& mk_name) throw (exception); 
    extern StreamProgress* mkProgress(const string& mk_name) throw (exception); 
    extern LinkerResults* results() throw (exception);
    extern void closeAll() throw (exception);
}

namespace ComDefines{
    extern int trash_size;
    extern char trash[];
}

#define MAX_SERVICE_FACTORY 10000

#define instanceof(obj , type) (dynamic_cast<type>(obj) != NULL)


//#define PRINT
//#define DEBUG
//#define DEBUG_PAUSE


#define NEXT_INT(input,x) input>>x; input.getline(ComDefines::trash, ComDefines::trash_size, '\n');
#define NEXT_DBL(input,x) input>>x; input.getline(ComDefines::trash, ComDefines::trash_size, '\n'); x = (fabs(x)<1e-9 ? 0 : x);
#define NEXT_STR(input,x) input>>x; input.getline(ComDefines::trash, ComDefines::trash_size, '\n');
#define NEXT(input,x) input>>x;

#ifdef PRINT
    #include <cstdio>
    #include <cmath>
    #include <cstdlib>
    #include <iostream>
    using namespace std;
    #define PRINTF_1(x) printf(x); cout.flush();
    #define PRINTF_2(x,y) printf(x,y); cout.flush();
    #define PRINTF_3(x,y,z) printf(x,y,z); cout.flush();
    #define PRINTF_4(x,y,z,k) printf(x,y,z,k); cout.flush();
    #define PRINTF_5(x,y,z,k,m) printf(x,y,z,k,m); cout.flush();
    #define PRINTF_6(x,y,z,k,m,n) printf(x,y,z,k,m,n); cout.flush();
    #define NEXT_TRASH(input) input.getline(ComDefines::trash, ComDefines::trash_size, '\n'); printf("%s\n",ComDefines::trash); cout.flush();
#else
    #define PRINTF_1(x)
    #define PRINTF_2(x,y)
    #define PRINTF_3(x,y,z)
    #define PRINTF_4(x,y,z,k)
    #define PRINTF_5(x,y,z,k,m)
    #define PRINTF_6(x,y,z,k,m,n)
    #define NEXTLINE(input)
    #define NEXT_TRASH(input) input.getline(ComDefines::trash, ComDefines::trash_size, '\n');
#endif

#ifdef DEBUG
    #include <cstdio>
    #include <cstdlib>
    #include <iostream>
    using namespace std;
    #ifdef DEBUG_PAUSE
        #define DEBUGF_1(x) printf(x); cout.flush(); system("pause");
        #define DEBUGF_2(x,y) printf(x,y); cout.flush(); system("pause");
        #define DEBUGF_3(x,y,z) printf(x,y,z); cout.flush(); system("pause");
        #define DEBUGF_4(x,y,z,k) printf(x,y,z,k); cout.flush(); system("pause");
        #define DEBUGF_5(x,y,z,k,m) printf(x,y,z,k,m); cout.flush(); system("pause");
        #define DEBUGF_6(x,y,z,k,m,n) printf(x,y,z,k,m,n); cout.flush(); system("pause");
        #define DEBUGF_7(x,y,z,k,m,n,o) printf(x,y,z,k,m,n,o); cout.flush(); system("pause");
        #define DEBUGF_8(x,y,z,k,m,n,o,p) printf(x,y,z,k,m,n,o,p); cout.flush(); system("pause");
        #define DEBUGF_9(x,y,z,k,m,n,o,p,q) printf(x,y,z,k,m,n,o,p,q); cout.flush(); system("pause");
    #else
        #define DEBUGF_1(x) printf(x); cout.flush();
        #define DEBUGF_2(x,y) printf(x,y); cout.flush();
        #define DEBUGF_3(x,y,z) printf(x,y,z); cout.flush();
        #define DEBUGF_4(x,y,z,k) printf(x,y,z,k); cout.flush();
        #define DEBUGF_5(x,y,z,k,m) printf(x,y,z,k,m); cout.flush();
        #define DEBUGF_6(x,y,z,k,m,n) printf(x,y,z,k,m,n); cout.flush();
        #define DEBUGF_7(x,y,z,k,m,n,o) printf(x,y,z,k,m,n,o); cout.flush();
        #define DEBUGF_8(x,y,z,k,m,n,o,p) printf(x,y,z,k,m,n,o,p); cout.flush();
        #define DEBUGF_9(x,y,z,k,m,n,o,p,q) printf(x,y,z,k,m,n,o,p,q); cout.flush();
    #endif
#else
    #define DEBUGF_1(x)
    #define DEBUGF_2(x,y)
    #define DEBUGF_3(x,y,z)
    #define DEBUGF_4(x,y,z,k)
    #define DEBUGF_5(x,y,z,k,m)
    #define DEBUGF_6(x,y,z,k,m,n)
    #define DEBUGF_7(x,y,z,k,m,n,o)
    #define DEBUGF_8(x,y,z,k,m,n,o,p)
    #define DEBUGF_9(x,y,z,k,m,n,o,p,q)
#endif


#include <vector>
#include <iostream>

template<typename T>
std::ostream &operator<<( std::ostream & out, const std::vector<T> & vet ){
    if(vet.size()==0){
        out << "[]";
    }else{
        out << "[ ";
        for(int i=0; i<vet.size(); i++){
            out << vet[i] << " ";
        }
        out << "]";
    }
    return out;
}

template<typename T>
bool find( const std::vector<T>& vet , const T& val ){
    for(int i=0; i<vet.size(); i++){
        if(vet[i]==val){
            return true;
        }
    }
    return false;
}

#endif	/* COMDEFINES_H */

