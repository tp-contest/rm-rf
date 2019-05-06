//
// Created by d on 05.05.19.
//

#ifndef PRJ_USERHANDLER_H
#define PRJ_USERHANDLER_H

#include "Handler.h"
#include "User.h"
#include <iostream>

class UserHandler: public Handler {
public:
    UserHandler(): next(nullptr) {};
    ~UserHandler() {};

    void printHelp() {
        std::cout << "commands:" << std::endl;
    };

    void setNext(Handler *& handler) override {
        next = handler;
    };

    bool handle(int commandId, User *& user) override {

        if (commandId == LOGOUT) {
            logout(user);
        } else if (commandId == HELP) {
            printHelp();
        } else {
            if (user->isAdmin()) {
                if (next) {
                    next->handle(commandId, user);
                } else {
                    std::cout << "has no handler for admin!" << std::endl;
                    return false;
                }
            }
            return false;
        }
        return true;
    };

    bool logout(User *& user) {
        puts("hello logout");
        delete(user);
        user = nullptr;
        return true;
    }

private:
    Handler * next;
};

#endif //PRJ_USERHANDLER_H
