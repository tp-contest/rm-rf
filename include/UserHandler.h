//
// Created by d on 05.05.19.
//

#ifndef PRJ_USERHANDLER_H
#define PRJ_USERHANDLER_H

#include "Handler.h"
#include "User.h"
#include "Document.h"
#include <iostream>

class UserHandler: public Handler {
public:
    UserHandler() {};
    ~UserHandler() {};

    void printHelp() {
        std::cout << "commands:" << std::endl;
    };

    bool handle(int commandId, User *& user) override {
        bool result = true;
        if (!user) {
            return false;
        }

        if (commandId == LOGOUT) {
            result = logout(user);
        } else if (commandId == HELP) {
            printHelp();
        } else {
            return false;
        }
        return result;
    };

    bool logout(User *& user) {
        delete(user);
        user = nullptr;
        return true;
    }

    bool loadFile() {
        /*std::cout << "Enter path to file" << std::endl;
        Document * document = new Document();
        document.*/

    }

    bool pushFiles() {

    }

private:
    Handler * next;
};

#endif //PRJ_USERHANDLER_H
