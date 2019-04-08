//
// Created by d on 07.04.19.
//

#ifndef PRJ_ISUBSCRIBER_H
#define PRJ_ISUBSCRIBER_H

#include <string>

class ISubscriber {
public:
    virtual void handleServerAnswer(const std::string & answer) = 0;
};


#endif //PRJ_ISUBSCRIBER_H
