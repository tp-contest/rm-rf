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

//TODO:: create enum status list
typedef int status;

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
    status registration(const string name, const string login, const string password);
    status authorization();
    status logout() { return 101; };
    status rename(string name);
    status changePassword(string oldPass, string newPass) { return 101; };
    status setSessionId(string sessionId) {
        this->sessionId;
        return ERROR;
    };
};

#endif //_LIB_PERSON_H
