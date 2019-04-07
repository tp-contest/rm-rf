#ifndef MYPROJECT_PERSON_H
#define MYPROJECT_PERSON_H

#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;


class Person {
private:
    int ID;
    string login;
    string password;
    string name;
    bool isAdmin;
public:
    Person();
    ~Person();
    bool registration(string name, string login, string password);
    bool authorization(string login, string password);
    bool logout();
    bool rename(string name);
    bool changePassword(string oldPass, string newPass);
};

/*class User: public Person{
private:
    list<Contest> participation;
public:
    bool applyForContest(Contest newParticipation);
};

class Admin: public Person{
private:
public:
};*/


#endif //MYPROJECT_PERSON_H
