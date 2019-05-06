//
// Created by d on 07.04.19.
//

#ifndef PRJ_HANDLER_H
#define PRJ_HANDLER_H

#include <string>
#include "User.h"

enum commands { HELP, SIGNUP, LOGIN, LOGOUT, PUSHTOSERVER };

class Handler {
private:
    bool readyDataBit = false;

public:
    Handler() {};
    ~Handler() {};
    //virtual void pushToServer(const std::string & mess) = 0;

    virtual void printHelp() = 0;
    virtual bool handle(int commandId, User *& user) = 0;
    virtual void setNext(Handler *& handler) = 0;

    int requestToId(std::string request) {
        if (request == "login") {
            return LOGIN;
        } else if (request == "logout") {
            return LOGOUT;
        } else if (request == "signup") {
            return SIGNUP;
        } else if (request == "help") {
            return HELP;
        }
    }

};


#endif //PRJ_HANDLER_H
