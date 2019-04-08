//
// Created by d on 07.04.19.
//

#ifndef PRJ_SUBSCRIBER_H
#define PRJ_SUBSCRIBER_H

#include "ISubscriber.h"
#include "Handler.h"
#include "iostream"

class Subscriber : public ISubscriber {
private:
    Handler * handler;
    bool checkAnswer(const std::string & answer);
public:
    Subscriber() {
        handler = nullptr;
    };

    Subscriber(Handler & hdlr) {
        handler = &hdlr;
    }
    ~Subscriber() override {};

    void handleServerAnswer(const std::string & answer) override {
        std::cout << answer << std::endl;
        handler->getInfo();
    };
};


#endif //PRJ_SUBSCRIBER_H
