//
// Created by d on 05.05.19.
//

#ifndef PRJ_ADMINHANDLER_H
#define PRJ_ADMINHANDLER_H

#include "Handler.h"
#include <iostream>

class AdminHandler : public Handler {
public:
    AdminHandler() {};
    ~AdminHandler() {};

    void printHelp() {
        std::cout << "commands:" << std::endl;
    };

    bool handle(int commandId, User *& user) override {

        if (!user || (user && !user->isAdmin())) {
            return false;
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
};


#endif //PRJ_ADMINHANDLER_H
