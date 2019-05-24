//
// Created by d on 05.05.19.
//

#ifndef PRJ_NOUSERHANDLER_H
#define PRJ_NOUSERHANDLER_H

#include "Handler.h"
#include "User.h"
#include <iostream>

class NoUserHandler: public Handler {
public:
    NoUserHandler() {};
    ~NoUserHandler() {};

    void printHelp() override {
        std::cout << "commands:" << std::endl;
    };

    bool handle(int commandId, User *& user) override {
        bool result = true;
        if (user) {
            return false;
        }

        if (commandId == SIGNUP) {
            result = signUp(user);
        } else if (commandId == LOGIN) {
            result = login(user);
        } else if (commandId == HELP) {
            printHelp();
        } else {
            return false;
        }
        return result;
    };

    bool signUp(User *& user) {
        std::string username;
        std::string password1;
        std::string password2;

        std::cout << "username:";
        std::cin >> username;

        std::cout << "password:";
        std::cin >> password1;

        std::cout << "repeat password:";
        std::cin >> password2;

        if (password1.compare(password2)) {
            std::cout << "passwords do not match" << std::endl;
        }

        // TODO: push user to server //

        user = new User(username, password1);
        return true;

    }

    bool login(User *& user) {
        std::string username;
        std::string password;

        std::cout << "username:";
        std::cin >> username;

        std::cout << "password:";
        std::cin >> password;

        // TODO: check if user exists//

        user = new User(username, password);

        return true;
    }

    bool loginAsAdmin(User *& user) {
        bool result = login(user);
        user->makeAdmin();
        return result;
    }

    bool addUserFile(std::string path) {

        return true;
    }
};

#endif //PRJ_NOUSERHANDLER_H
