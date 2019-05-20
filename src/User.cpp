//
// Created by Sanya on 06.05.2019.
//

#include "User.h"
//#include "../include/Status.h"

void User::addContest(Contest &contest) {
    documents.insert(std::pair<std::string, Document>("", contest));
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
    documents.erase(contestID);
}

Contest *User::showContestByUser(const string &userID) {
    return nullptr;
}

Contest *User::showContest(const string &contestID) {
    return nullptr;
}

string User::showResult(const string &contestID, const string &userID) {
    return nullptr;
}
