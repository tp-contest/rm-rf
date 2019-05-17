//
// Created by horosheninad
//

#include "../include/Admin.h"
#include "../include/Handler.h"
#include "../include/Status.h"

Status Admin::editContest(const string &contestId, const string &title, const string &task, time_t deadline) {
    Contest contest = contests.find(contestId)->second;
    if (!contest.editTask(task)) {
        return ERROR;
    }
    if (!contest.editTitle(title)) {
        return ERROR;
    }
    if (!contest.editDeadline(deadline)) {
        return ERROR;
    }
    contests.at(contestId) = contest;
    return Ok;
};

string Admin::createContest(const string &title, const string &task, time_t deadline) {
    Contest contest(title, task, deadline);
    contests.insert(std::pair<string, Contest>(contest.getContestId(), contest));
    return contest.getContestId();
}

Status Admin::deleteContest(const string &contestID) {
    contests.erase(contestID);
    return Ok;
}

StatContest *Admin::getStatUsersByContest(const string &contestID) {
    StatContest *stat = subscriber->GetStatUserByContest(contestID);
    return stat;
}

StatContest *Admin::getStatContest(const string &contestID) {
    StatContest *stat = subscriber->GetStatContest(contestID);
    return stat;
}

StatContest *Admin::showContestByUser(const string &userID) {
    StatContest *stat = subscriber->ShowContestByUser(userID);
    return stat;
}

StatCommit *Admin::showCommits(const string &contestID) {
    StatCommit *commit = subscriber->ShowCommits(contestID);
    return commit;
}

string Admin::openUserCodeForLastCommit(const string &contestID) const {
    string code = subscriber->OpenUserCodeForLastCommit(contestID);
    return code;
}
