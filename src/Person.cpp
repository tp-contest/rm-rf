//
// Created by horosheninad
//

#include "../include/Person.h"
#include "../include/Subscriber.h"

Status Person::registration(const string &newName, const string &newLogin, const string &newPassword) {
    if (newPassword.empty() || newLogin.empty()) {
        return ERROR;
    }
    if (Ok != subscriber->SendToServerReg(newName, newLogin, newPassword)) {
        return ERROR;
    }
    this->password = newPassword; // utils.createPassword()
    this->login = newLogin; // utils.createLogin()
    this->name = newName; // utils.createName()
    return Ok;
}

Status Person::authorization() {
    if (Ok != subscriber->SendToServerAuth(this->sessionId)) {
        return ERROR;
    }
    return Ok;
}

Status Person::rename(const string &renameField) {
    if (renameField.empty() || Ok != subscriber->SendToServerRename(renameField)) {
        return ERROR;
    }
    this->name = renameField;
    return Ok;
}

Status Person::logout() {
    if (this->sessionId.empty() || Ok != subscriber->SendToServerLogout()) {
        return ERROR;
    }
    // TODO::redirect to start page
    this->sessionId.clear();
    return Ok;
}

Status Person::changePassword(const string &oldPass, const string &newPass) {
    if (oldPass == this->password) {
        return ERROR;
    }
    if (newPass.empty() || subscriber->SendToServerChangePass(newPass)) {
        return ERROR;
    }
    this->password = newPass;
    return Ok;
}

Status Person::setSessionId(const string & sessId) {
    if (sessId.empty())
        return ERROR;
    this->sessionId = sessId;
    return Ok;
}

string Person::getSessionId() {
    return this->sessionId;
}