//
// Created by d on 07.04.19.
//

#ifndef PRJ_ISUBSCRIBER_H
#define PRJ_ISUBSCRIBER_H

#include <string>
//#include "Handler.h"

class ISubscriber {
//protected:
//    Handler * handler;
public:
    //ISubscriber() {};
    virtual ~ISubscriber() {};
    virtual void handleServerAnswer(const std::string & answer) = 0;
};


#endif //PRJ_ISUBSCRIBER_H
