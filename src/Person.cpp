//
// Created by horosheninad
//

#include "../include/Person.h"

Status Person::registration(const string name, const string login, const string password) {
    this->password = password; // utils.createPassword()
    this->login = login; // utils.createLogin()
    this->name = name; // utils.createName()
    this->ID = "2133"; // utils.createUUID()
    return Ok;
}

Status Person::authorization()  {
    // handler sessionId
    return ERROR;
}

Status Person::rename(string name)  {
    return ERROR;
}