//
// Created by d on 05.05.19.
//

#ifndef PRJ_ADMINHANDLER_H
#define PRJ_ADMINHANDLER_H

#include "Handler.h"
#include <iostream>

class AdminHandler : public Handler {
public:
    AdminHandler() : next(nullptr) {};
    ~AdminHandler() {};

    void printHelp() {
        std::cout << "commands:" << std::endl;
    };

    void setNext(Handler *& handler) override {
        next = handler;
    };

    bool handle(int commandId, User *& user) override {

        if (user->isAdmin()) {
            if (next) {
                next->handle(commandId, user);
            } else {
                std::cout << "has no handler for login user!" << std::endl;
                return false;
            }
        }

        if (commandId == LOGOUT) {
            logout(user);
        } else if (commandId == HELP) {
            printHelp();
        } else {
            return false;
        }

        return true;
    };

    bool logout(User *& user) {
        delete(user);
        user = nullptr;
        return true;
    }

private:
    Handler * next;
};


#endif //PRJ_ADMINHANDLER_H
