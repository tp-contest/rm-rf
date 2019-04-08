//
// Created by d on 07.04.19.
//

#ifndef PRJ_JSONPARSER_H
#define PRJ_JSONPARSER_H

#include "Parser.h"
#include "Subscriber.h"

class JsonParser: public Parser {
private:
    Subscriber * subscriber;
public:
    void parseRequest() override ;
};


#endif //PRJ_JSONPARSER_H
