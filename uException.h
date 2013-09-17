/* 
 * File:   Exception.h
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 20:18
 */

#ifndef UEXCEPTION_H
#define	UEXCEPTION_H

#include <assert.h>

#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <typeinfo>
#include <sstream>

using std::exception;
using std::string;
using std::ostringstream;
using std::type_info;
using std::vector;
using std::cout;
using std::endl;

class uException : public exception{
public:
    uException(const string &msg);
    uException(const uException& orig);
    virtual ~uException()throw(){}
    virtual const char* what() const throw();
    virtual const string& msg() const throw();
private:
    string s;
};

namespace EXCEPTION{
    extern vector<string> stack;
    extern bool frist;
}


#define NEXT_LINE(ptr)\
    {\
        char c;\
        do{c = fgetc (ptr);}while(c != feof(ptr) && c!='\n');\
    }

#define CMD_TRY(CMD, MSG)\
    try{\
        CMD;\
    }catch(exception& ex){\
        EXCEPTION::frist = true;\
        cout.flush();\
        ostringstream out;\
        out << ex.what() << endl;\
        out << "\tat file("<<__FILE__<<"), line("<<__LINE__<<") "<<MSG;\
        throw uException(out.str());\
    }catch(...){\
        EXCEPTION::frist = true;\
        cout.flush();\
        ostringstream out;\
        out << "exception unkwon catch(...)" << endl;\
        out << "\tat file("<<__FILE__<<"), line("<<__LINE__<<") "<<MSG;\
        throw uException(out.str());\
    }

#define CALL_FV(F)\
    CMD_TRY(F,"call function: " #F);

#define CALL_FR(x, F)\
    CMD_TRY(x=F,"call function: " #F);

#define CALL_MV(F)\
    CMD_TRY(F,"in class '"<<typeid(this).name()<<"' call member: " #F);

#define CALL_MR(x, F)\
    CMD_TRY(x = F,"in class '"<<typeid(this).name()<<"' call member: " #F);


#define REC_CALL_TRY_V(call)\
    if(EXCEPTION::frist){\
        EXCEPTION::frist = false;\
        call\
        return;\
    }else{\
        EXCEPTION::frist = true;\
    };
#define REC_CALL_TRY_R(TYPE, call)\
    if(EXCEPTION::frist){\
        EXCEPTION::frist = false;\
        TYPE r;\
        call\
        return r;\
    }else{\
        EXCEPTION::frist = true;\
    };

#define DEF_FUNCTION_V(F)\
    REC_CALL_TRY_V( CMD_TRY(F,"define function: " #F) );

#define DEF_FUNCTION_R(TYPE, F)\
    REC_CALL_TRY_R( TYPE, CMD_TRY(r=F,"define function: " #F) );

#define DEF_MEMBER_V(F)\
    REC_CALL_TRY_V( CMD_TRY(F,"in class '"<<typeid(this).name()<<"' define member: " #F) );

#define DEF_MEMBER_R(TYPE, F)\
    REC_CALL_TRY_R( TYPE, CMD_TRY(r = F,"in class '"<<typeid(this).name()<<"' define member: " #F); );


#define THROW(M)\
    cout.flush();\
    ostringstream out;\
    out << "in file("<<__FILE__<<"), line("<<__LINE__<<")"<<endl;\
    out << "\twhat: "<<M;\
    throw uException(out.str());

#define THROWF1(F,X)\
    cout.flush();\
    printf("in file(%s), line(%d)\n", __FILE__, __LINE__);\
    printf("\twhat: "F,X);\
    ostringstream out;\
    out << "in file("<<__FILE__<<"), line("<<__LINE__<<")"<<endl;\
    out << "\twhat: "<<F;\
    throw uException(out.str());


#define ASSERT(expression)\
    if(!(expression)){\
        cout.flush();\
        ostringstream out;\
        out << "in file("<<__FILE__<<"), line("<<__LINE__<<")"<<endl;\
        out << "\twhat: ASSERT("<<#expression<<")";\
        throw uException(out.str());\
    }

#define MEMBER {\
    try{\
        ostringstream out;\
        out << "\tat file("<<__FILE__<<"), line("<<__LINE__<<") "<<"in class '"<<typeid(this).name()<<"' member definition";\
        EXCEPTION::stack.push_back(out.str());

#define FUNCTION {\
    try{\
        ostringstream out;\
        out << "\tat file("<<__FILE__<<"), line("<<__LINE__<<") "<<"in function definition";\
        EXCEPTION::stack.push_back(out.str());

#define BLOCK {\
    try{\
        ostringstream out;\
        out << "\tat file("<<__FILE__<<"), line("<<__LINE__<<") "<<"in block definition";\
        EXCEPTION::stack.push_back(out.str());

#define RETURN EXCEPTION::stack.pop_back(); return

#define END\
        EXCEPTION::stack.pop_back();\
    }catch(exception& ex){\
        EXCEPTION::frist = true;\
        cout.flush();\
        ostringstream out;\
        out << ex.what() << endl;\
        out << EXCEPTION::stack.back();\
        EXCEPTION::stack.pop_back();\
        throw uException(out.str());\
    }catch(...){\
        EXCEPTION::frist = true;\
        cout.flush();\
        ostringstream out;\
        out << "exception unkwon catch(...)" << endl;\
        out << EXCEPTION::stack.back();\
        EXCEPTION::stack.pop_back();\
        throw uException(out.str());\
    }\
}

#endif	/* EXCEPTION_H */

