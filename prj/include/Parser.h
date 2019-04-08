//
// Created by d on 07.04.19.
//

#ifndef PRJ_PARSER_H
#define PRJ_PARSER_H

#include <string>

class Parser {
public:
    virtual std::string parseRequest(const std::string & jsonMess) = 0; // return Document
};


#endif //PRJ_PARSER_H
