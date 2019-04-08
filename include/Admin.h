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
    string createContest(string title, string task, time_t deadline) {
        Contest contest(title, task, deadline);
        contests.insert(std::pair<string, Contest>(contest.getContestId(), contest));
        return contest.getContestId();
    };
    status editContest(string contestId, string title, string task, time_t deadline) {
        Contest contest = contests.find(contestId)->second;
        if (!contest.editTask(task)) {
            return -1;
        }
        if (!contest.editTitle(title)) {
            return -1;
        }
        if (!contest.editDeadline(deadline)) {
            return -1;
        }
        contests.at(contestId) = contest;
        return 101;
    };
    status deleteContest(string contestId) {
        contests.erase(contestId);
        return 101;
    };
    status getStatUsersByContest(string contestId) {
        Handler handler;
        return handler.getStatUsersByContest(contestId);
    };
    status getStatContest(string contestId) {
        Handler handler;
        return handler.getStatContest(contestId);
    };
    status showContestByUser(string userId) {
        Handler handler;
        return handler.showContestByUser(userId);
    };
    status showUsersCommitsByContest(string contestId) {
        Handler handler;
        return handler.showUsersCommitsByContest(contestId);
    };
    status openUserCodeFromLastCommit(string commitId) {
        Handler handler;
        return handler.openUserCodeFromLastCommit(commitId);
    };
};

#endif //RM_RF_ADMIN_H
