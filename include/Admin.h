//
// Created by horosheninad
//

#ifndef RM_RF_ADMIN_H
#define RM_RF_ADMIN_H

#include "Person.h"
#include "Contest.h"
#include "../handler/handler.h"
#include "map"

using std::string;
using std::list;
using std::map;

//TODO:: create enum status list
typedef int status;

class Admin: public Person {
private:
    map<string, Contest> contests;
public:
    Admin() {}
    ~Admin() {}
    string createContest(string title, string task, time_t deadline);
    status editContest(string contestId, string title, string task, time_t deadline);
    status deleteContest(string contestId);
    status getStatUsersByContest(string contestId);
    status getStatContest(string contestId);
    status showContestByUser(string userId);
    status showUsersCommitsByContest(string contestId);
    status openUserCodeFromLastCommit(string commitId);
};

#endif //RM_RF_ADMIN_H
