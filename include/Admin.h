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
using std::map;

class Admin: public Person {
private:
    map<string, Contest> contests;
public:
    Admin() {}
    ~Admin() {}

    string createContest(const string &title, const string &task, time_t deadline);

    Status editContest(const string &contestId, const string &title, const string &task, time_t deadline);

    Status deleteContest(const string &contestID);

    StatContest *getStatUsersByContest(const string &contestID);

    StatContest *getStatContest(const string &contestID);

    StatContest *showContestByUser(const string &userID);

    StatCommit *showCommits(const string &contestID);

    string openUserCodeForLastCommit(const string &contestID) const;
};

#endif //RM_RF_ADMIN_H
