//
// Created by horosheninad
//

#ifndef _LIB_PERSON_H
#define _LIB_PERSON_H

#include <iostream>
#include <string>
#include <list>
#include "Status.h"

using std::string;
using std::list;

class Person {
private:
    string ID;
    string login;
    string password;
    string name;
    string sessionId;
public:
    Person() {};
    ~Person() {};
    Status registration(const string name, const string login, const string password);
    Status authorization();
    Status logout();
    Status rename(string renameField);
    Status changePassword(string oldPass, string newPass) { return Ok; };
    Status setSessionId(string sessionId) {
        this->sessionId = sessionId;
        return ERROR;
    };
};

#endif //_LIB_PERSON_H
