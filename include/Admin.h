//
// Created by horosheninad
//

#ifndef RM_RF_ADMIN_H
#define RM_RF_ADMIN_H

#include "Person.h"
#include "Contest.h"
#include "Handler.h"
#include "map"

using std::string;
using std::list;
using std::map;

class Admin: public Person {
private:
    map<string, Contest> contests;
public:
    Admin() {}
    ~Admin() {}
    string createContest(string title, string task, time_t deadline);
    Status editContest(string contestId, string title, string task, time_t deadline);
    Status deleteContest(string contestId);
};

#endif //RM_RF_ADMIN_H
