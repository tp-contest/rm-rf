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
    NoUserHandler(): next(nullptr) {};
    ~NoUserHandler() {};

    void printHelp() override {
        std::cout << "commands:" << std::endl;
    };

    void setNext(Handler *& handler) override {
        next = handler;
    };


    bool handle(int commandId, User *& user) override {
        if (user) {
            if (next) {
                next->handle(commandId, user);
            } else {
                std::cout << "has no handler for login user!" << std::endl;
                return false;
            }
        }

        if (commandId == SIGNUP) {
            signUp(user);
        } else if (commandId == LOGIN) {
            login(user);
        } else if (commandId == HELP) {
            printHelp();
        } else {
            return false;
        }
        return true;
    };

    bool signUp(User *& user) {
        puts("hello signup");
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
        puts("hello login");
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

private:
    Handler * next;
};

#endif //PRJ_NOUSERHANDLER_H
