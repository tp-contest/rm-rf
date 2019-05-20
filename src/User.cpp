//
// Created by Sanya on 06.05.2019.
//

#include "User.h"

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

Status User::registration(const string &newName, const string &newLogin, const string &newPassword) {
    if (newPassword.empty() || newLogin.empty()) {
        return ERROR;
    }
    if (Ok != subscriber->SendToServerReg(newName, newLogin, newPassword)) {
        return ERROR;
    }
    this->password = newPassword;
    this->username = newName;
    return Ok;
}

Status User::authorization() {
    if (Ok != subscriber->SendToServerAuth(this->sessionId)) {
        return ERROR;
    }
    return Ok;
}

Status User::rename(const string &renameField) {
    if (renameField.empty() || Ok != subscriber->SendToServerRename(renameField)) {
        return ERROR;
    }
    this->name = renameField;
    return Ok;
}

Status User::logout() {
    if (this->sessionId.empty() || Ok != subscriber->SendToServerLogout()) {
        return ERROR;
    }
    // TODO::redirect to start page
    this->sessionId.clear();
    return Ok;
}

Status User::changePassword(const string &oldPass, const string &newPass) {
    if (oldPass == this->password) {
        return ERROR;
    }
    if (newPass.empty() || subscriber->SendToServerChangePass(newPass)) {
        return ERROR;
    }
    this->password = newPass;
    return Ok;
}

Status User::setSessionId(const string & sessId) {
    if (sessId.empty())
        return ERROR;
    this->sessionId = sessId;
    return Ok;
}

string User::getSessionId() {
    return this->sessionId;
}

Status User::editContest(const string &contestId, const string &title, const string &task, time_t deadline) {
    Contest contest = documents.find(contestId)->second;
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

string User::createContest(const string &title, const string &task, time_t deadline) {
    Contest contest(title, task, deadline);
    contests.insert(std::pair<string, Contest>(contest.getContestId(), contest));
    return contest.getContestId();
}

Status User::deleteContest(const string &contestID) {
    contests.erase(contestID);
    return Ok;
}

StatContest* User::getStatUsersByContest(const string &contestID) {
    StatContest *stat = subscriber->GetStatUserByContest(contestID);
    return stat;
}

StatContest* User::getStatContest(const string &contestID) {
    StatContest *stat = subscriber->GetStatContest(contestID);
    return stat;
}

StatContest* User::showContestByUser(const string &userID) {
    StatContest *stat = subscriber->ShowContestByUser(userID);
    return stat;
}

StatCommit* User::showCommits(const string &contestID) {
    StatCommit *commit = subscriber->ShowCommits(contestID);
    return commit;
}

string User::openUserCodeForLastCommit(const string &contestID) const {
    string code = subscriber->OpenUserCodeForLastCommit(contestID);
    return code;
}