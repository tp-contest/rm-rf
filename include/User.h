<<<<<<< HEAD
#ifndef MYPROJECT_USER_H
#define MYPROJECT_USER_H

#include <map>
#include "Person.h"
#include "Contest.h"
#include "Status.h"

using std::map;

class User : public Person {
private:
    map<string, Contest> contests;
public:
    Status applyForContest(Contest &newContest);

    Contest *showContestByUser(const string &userID);

    Contest *showContest(const string &contestID);

    string showResult(const string &contestID, const string &userID);

    Status sendCommit(string &ContestID, Commit &commit);

    void addContest(Contest &contest);

    void deleteContest(const string &contestID);
};

#endif //MYPROJECT_USER_H
=======
//
// Created by d on 05.05.19.
//

#ifndef PRJ_USER_H
#define PRJ_USER_H

#include <iostream>

class User {
public:
    User() {}

    User(std::string username, std::string password) : username(username), password(password), admin(false) {
        std::cout << "got user" << std::endl;
    }

    ~User() {}

    bool isAdmin() {
        return admin;
    }

private:
    std::string username;
    std::string password;
    bool admin;
};

#endif //PRJ_USER_H
>>>>>>> origin/efimova
