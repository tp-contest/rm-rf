//
// Created by d on 07.04.19.
//

#ifndef PRJ_SUBSCRIBER_H
#define PRJ_SUBSCRIBER_H

#include "ISubscriber.h"
#include "Handler.h"
#include "Parser.h"
#include "iostream"
#include "Status.h"

class Subscriber : public ISubscriber {
private:
    Handler * handler;
    Parser * parser;
    bool checkAnswer(const std::string & answer);

public:
    Subscriber() : handler(nullptr), parser(nullptr){};
    Subscriber(Handler & hdlr, Parser & prsr) {
        handler = &hdlr;
        parser = &prsr;
    }
    ~Subscriber() override {};

    void handleServerAnswer(const std::string & answer) override {
        if (handler != nullptr && answer.c_str() != nullptr) {
            handler->getInfo();
            std::cout << answer << std::endl;
        }
    };

    Handler * getHandler() {
        return handler;
    }

    Parser * getParser() {
        return parser;
    }

    Status SendToServerAuth(const string &sessionId) {
        return Ok;
    }
    Status SendToServerReg(const string &newName, const string &newLogin, const string &newPassword) {
        return Ok;
    }
    Status SendToServerRename(const string &renameField) {
        return Ok;
    }
    Status SendToServerLogout() {
        return Ok;
    }
    Status SendToServerChangePass(const string &newPass) {
        return Ok;
    }
};


#endif //PRJ_SUBSCRIBER_H
