//
// Created by d on 07.04.19.
//

#ifndef PRJ_ISUBSCRIBER_H
#define PRJ_ISUBSCRIBER_H

#include <string>
#include "Handler.h"

class ISubscriber {
private:
    Handler * handler;
public:
    virtual void handleServerAnswer(const std::string & answer);
};


#endif //PRJ_ISUBSCRIBER_H
