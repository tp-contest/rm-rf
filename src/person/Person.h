//
// Created by horosheninad
//

#ifndef _LIB_PERSON_H
#define _LIB_PERSON_H

#include <iostream>
#include <string>
#include <list>

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
    Person() {
        this->password = "1111"; // utils.createPassword()
        this->login = "sanya"; // utils.createLogin()
        this->name = "sss"; // utils.createName()
        this->ID = "2133"; // utils.createUUID()
    }
    Person(string name, string login, string password) : name(name), login(login), password(password) {};
    ~Person() {};
    status registration() {};
    status authorization() {};
    status logout() {};
    status rename(string name) {};
    status changePassword(string oldPass, string newPass) {};
};

#endif //_LIB_PERSON_H
