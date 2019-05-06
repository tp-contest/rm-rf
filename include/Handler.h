//
// Created by d on 07.04.19.
//

#ifndef PRJ_HANDLER_H
#define PRJ_HANDLER_H

#include <string>

class Handler {
private:
    bool readyDataBit = false;
public:
    Handler() {};
    ~Handler() {};
    virtual void pushToServer(const std::string & mess) = 0;
    virtual void getInfo() = 0;
};


#endif //PRJ_HANDLER_H
