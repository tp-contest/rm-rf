//
// Created by horosheninad
//

#ifndef _LIB_PERSON_H
#define _LIB_PERSON_H

#include <iostream>
#include <string>
#include <list>
#include "Status.h"
#include "Subscriber.h"

using std::string;
using std::list;

class Person {
protected:
    string ID;
    string login;
    string password;
    string name;
    string sessionId;
    Subscriber * subscriber;
public:
//    Person() {};
    ~Person() {};
    Status registration(const string &newName, const string &newLogin, const string &newPassword);
    Status authorization();
    Status logout();
    Status rename(const string &renameField);
    Status changePassword(const string &oldPass, const string &newPass);
    Status setSessionId(const string &sessId);
    string getSessionId();
};

#endif //_LIB_PERSON_H
