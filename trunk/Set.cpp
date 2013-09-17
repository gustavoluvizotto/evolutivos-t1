/* 
 * File:   Set.cpp
 * Author: marcio
 *
 * Created on 9 de Dezembro de 2012, 22:16
 */

#include <vector>
#include <assert.h>

#include "uException.h"
#include "Set.h"
#include "Node.h"
#include "Factory.h"
#include "ComDefines.h"
#include "SaveSgl.h"

using std::vector;

Set::Set(Node* serv, const Factory* fact) : s(serv), f(fact) {
    //assert(!(serv==NULL));
    //printf("s = %d\n", serv); cout.flush();
    //assert(!(fact==NULL));
    nm = string(s->name());
}

Set::~Set(){}

int Set::getID() const
MEMBER
    RETURN s->getID();
END
const vector<int>& Set::get_dads() const
MEMBER
    RETURN s->get_dads();
END
const string& Set::name() const
MEMBER
    RETURN nm;
END
bool Set::operator==(const Set &obj) const
MEMBER
    RETURN this->s->getID() == obj.s->getID();
END
Node* Set::serv() const
MEMBER
    RETURN s;
END
const Factory* Set::fact() const
MEMBER
    RETURN f;
END
void Set::parameters(SaveSgl *com)
MEMBER
    s->parameters(com);
END

