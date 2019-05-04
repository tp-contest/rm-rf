//
// Created by horosheninad
//

#include "../include/Person.h"

Status Person::registration(const string name, const string login, const string password) {
    if (password.empty() || login.empty()) {
        return ERROR;
    }
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

Status Person::rename(string renameField)  {
    if (renameField.empty()) {
        return ERROR;
    }
    this->name = renameField;
    return Ok;
}

Status Person::logout() {
    if (this->sessionId.empty()) {
        return ERROR;
    }
    this->sessionId.clear();
    return Ok;
}