//
// Created by d on 07.04.19.
//

#ifndef PRJ_JSONPARSER_H
#define PRJ_JSONPARSER_H

#include "Parser.h"
#include "Subscriber.h"
#include "Contest.h"
#include "JsonModels.h"
#include <boosr/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


namespace pt = boost::property_tree;

class JsonParser: public Parser {
private:
    Subscriber * subscriber;
public:

    int  JsonContest(const Contestjson &contest);

    int JsonHuman(const Humanjson &man);

    int JsonMyContest(const MyContestjson &contest);

    int JsonTask(const Taskjson &task);

};


#endif //PRJ_JSONPARSER_H
