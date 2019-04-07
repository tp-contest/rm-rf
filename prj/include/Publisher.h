//
// Created by d on 07.04.19.
//

#ifndef PRJ_PUBLISHER_H
#define PRJ_PUBLISHER_H

#include "ISubscriber.h"
#include "vector"

class Publisher {
public:
    bool subbscribe(const ISubscriber & subscriber);
    bool unsubbscribe(const ISubscriber & subscriber);
    bool notifySubscriber(const ISubscriber & subscriber);

private:
    std::vector<ISubscriber *> subscriber;
};


#endif //PRJ_PUBLISHER_H
