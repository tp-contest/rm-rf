#include "Person.h"

Person::Person() {

}

Person::~Person() {

}

status Person::registration(const string &name, const string &login, const string &password) {
    return OK;
}

status Person::authorization(const string &login, const string &password) {
    return OK;
}

status Person::logout() {
    return ERROR;
}

status Person::rename(const string &name) {
    return ERROR;

}

status Person::changePassword(const string &oldPass, const string &newPass) {
    return ERROR;

}
