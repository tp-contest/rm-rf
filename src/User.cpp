//
// Created by Sanya on 06.05.2019.
//
#include "../include/User.h"
#include "../include/Status.h"

void User::addContest(Contest &contest) {
    contests.insert(std::pair<string, Contest>(contest.getContestId(), contest));
}

Status User::sendCommit(string &ContestID, Commit &commit) {
    if (Ok != subscriber->SendCommit(commit)) {
        return ERROR;
    }
    return Ok;
}

Status User::applyForContest(Contest &newContest) {
    string contestId = newContest.getContestId();
    if (contestId.empty()) {
        return ERROR;
    }
    addContest(newContest);
    return Ok;
}

void User::deleteContest(const string &contestID) {
    contests.erase(contestID);
}
