//
// Created by d on 07.04.19.
//

#ifndef PRJ_PUBLISHER_H
#define PRJ_PUBLISHER_H

#include "ISubscriber.h"
#include "vector"
#include "string"

class Publisher {
private:
    //std::vector<ISubscriber *> subscribers;
    ISubscriber * subscriber;
public:
    Publisher() {};
    ~Publisher() {};

    bool addSubscriber(ISubscriber & mysubscriber) {
        *subscriber = mysubscriber;
        return true;
    };
    bool unsubbscribe(const ISubscriber & mysubscriber);
    bool notifySubscriber(ISubscriber & mysubscriber) {
        std::string myaswer = "ANSWER FROM SERVER";
        mysubscriber.handleServerAnswer(myaswer);
        return true;
    };

};


#endif //PRJ_PUBLISHER_H
