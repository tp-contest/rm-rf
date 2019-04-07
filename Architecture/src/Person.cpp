#include "Person.h"

Person::Person() {

}

Person::~Person() {

}

bool registration(string name, string login, string password) {
    return false;
}

bool Person::authorization(string login, string password) {
    return true;
}

bool Person::logout() {
    return false;
}

bool Person::rename(string name) {
    return false;

}

bool Person::changePassword(string oldPass, string newPass) {
    return false;

}
