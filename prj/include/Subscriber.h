//
// Created by d on 07.04.19.
//

#ifndef PRJ_SUBSCRIBER_H
#define PRJ_SUBSCRIBER_H

#include "ISubscriber.h"
#include "Handler.h"
#include "Parser.h"
#include "iostream"

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
        std::cout << answer << std::endl;
        handler->getInfo();
    };

    Handler * getHandler() {
        return handler;
    }

    Parser * getParser() {
        return parser;
    }
};


#endif //PRJ_SUBSCRIBER_H
