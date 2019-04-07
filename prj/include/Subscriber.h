//
// Created by d on 07.04.19.
//

#ifndef PRJ_SUBSCRIBER_H
#define PRJ_SUBSCRIBER_H

#include "ISubscriber.h"

class Subscriber : public ISubscriber {
public:
    Subscriber() {};
    ~Subscriber() {};

    void handleServerAnswer(const std::string & answer) override ;
};


#endif //PRJ_SUBSCRIBER_H
