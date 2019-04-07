//
// Created by d on 07.04.19.
//

#ifndef PRJ_HANDLER_H
#define PRJ_HANDLER_H

#include <string>
#include "Publisher.h"

class Handler {
private:
    Publisher * publisher;
    bool readyDataBit = false;
public:
    virtual void pushToServer(const std::string & mess);
    virtual void getInfo();
};


#endif //PRJ_HANDLER_H
