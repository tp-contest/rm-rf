//
// Created by d on 05.05.19.
//

#ifndef PRJ_USER_H
#define PRJ_USER_H

#include <iostream>

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
private:
    std::string username;
    std::string password;
    bool admin;
};

#endif //PRJ_USER_H
