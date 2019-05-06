//
// Created by horosheninad
//

#include "../include/Contest.h"

Contest::Contest(const string &name) {
    title_ = name;
    ID = "from server"; // tools.GenerateUUID();
}

Status Contest::editTitle(const string &new_title)  {
    if (title_.empty()) {
        return ERROR;
    }
    title_ = new_title;
    return Ok;
}

Status Contest::editDeadline(time_t deadline)  {
    if (deadline < 0) {
        return ERROR;
    }
    deadline_ = deadline;
    return Ok;
}

Status Contest::editTask(const string &task) {
    if (task == "") {
      return ERROR;
    }
    this->task = task;
    return Ok;;
}

Status Contest::addCommit(Commit &commit) {
    commits.insert(std::pair<string, Commit>(commit.getCommitId(), commit));
    return Ok;
}

Status Contest::changeTask(string Task) {
    return Ok;
}

Status Contest::changeLimits(int timeLimit, int memoryLimit) {
    return Ok;
}

Status Contest::changeDeadline(time_t deadline) {
    return Ok;
}

string Contest::getContestId() {
    return this->ID;
}
string Contest::getTitle() {
    return title_;
}