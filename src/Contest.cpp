//
// Created by horosheninad
//

#include "../include/Contest.h"

Contest::Contest(string title) {
    this->ID = '1'; // tools.GenerateUUID();
}

bool Contest::editTitle(string title)  {
    if (title == "") {
      return false;
    }
    this->title = title;
    return true;
}

bool Contest::editDeadline(time_t deadline)  {
    if (deadline < 0) {
      return false;
    }
    this->deadline = deadline;
    return true;
}

bool Contest::editTask(string task) {
    if (task == "") {
      return false;
    }
    this->task = task;
    return true;
}

Status Contest::addCommit(Commit &commit) {
    commits.insert(std::pair<string, Commit>(commit.getCommitId(), commit));
    return Ok;
}