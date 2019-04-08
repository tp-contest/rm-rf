#ifndef MYPROJECT_PERSON_H
#define MYPROJECT_PERSON_H

#include "status.h"

class Person {
private:
    string ID_;
    string login_;
    string password_;
    string name_;
    int sessionID_;
public:
    Person();

    ~Person();

    status registration(const string &name, const string &login, const string &password);

    status authorization(const string &login, const string &password);

    status logout();

    status rename(const string &name);

    status changePassword(const string &oldPass, const string &newPass);
};


#endif //MYPROJECT_PERSON_H
