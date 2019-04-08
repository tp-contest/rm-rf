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
    Person() {};
    ~Person() {};
    status registration(const string name, const string login, const string password) {
        this->password = password; // utils.createPassword()
        this->login = login; // utils.createLogin()
        this->name = name; // utils.createName()
        this->ID = "2133"; // utils.createUUID()
        return 101;
    };
    status authorization() {
        // handler sessionId
        return 101;
    };
    status logout() { return 101; };
    status rename(string name) {

        return 101;
    };
    status changePassword(string oldPass, string newPass) { return 101; };
    status setSessionId(string sessionId) {
        this->sessionId;
        return 101;
    }
};

#endif //_LIB_PERSON_H
