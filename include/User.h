#ifndef PRJ_USER_H
#define PRJ_USER_H

#include <iostream>
#include <map>
#include "Person.h"
#include "Contest.h"
#include "Status.h"

using std::map;

class User {
public:
    User(){}

    User(std::string username, std::string password): username(username), password(password), admin(false) {
        std::cout << "got user" << std::endl;
    }
    ~User(){}
    bool isAdmin(){
        return admin;
    }
    Status applyForContest(const Contest &newContest) { return Ok; };
    Status sendCommit(string ContestID) { return Ok };
private:
    std::string username;
    std::string password;
    map<string, Contest> contests_;
    bool admin;
};

#endif //PRJ_USER_H

