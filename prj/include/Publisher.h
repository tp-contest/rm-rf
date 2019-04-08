//
// Created by d on 07.04.19.
//

#ifndef PRJ_PUBLISHER_H
#define PRJ_PUBLISHER_H

#include "Subscriber.h"
#include "vector"

class Publisher {
private:
    std::vector<Subscriber *> subscribers;
public:
    Publisher();
    ~Publisher();
    bool subbscribe(const Subscriber & subscriber);
    bool unsubbscribe(const Subscriber & subscriber);
    bool notifySubscriber(const Subscriber & subscriber);

};


#endif //PRJ_PUBLISHER_H
