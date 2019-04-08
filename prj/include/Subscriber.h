//
// Created by d on 07.04.19.
//

#ifndef PRJ_SUBSCRIBER_H
#define PRJ_SUBSCRIBER_H

#include "ISubscriber.h"
#include "Handler.h"

class Subscriber : public ISubscriber {
private:
    Handler * handler;
public:
    Subscriber() {
        handler = nullptr;
    };
    ~Subscriber() {};

    void handleServerAnswer(const std::string & answer) override ;
};


#endif //PRJ_SUBSCRIBER_H
