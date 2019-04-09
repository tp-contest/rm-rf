//
// Created by horosheninad
//

#include "../include/Admin.h"
#include "../include/Handler.h"
#include "../include/Status.h"

Status Admin::editContest(string contestId, string title, string task, time_t deadline) {
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

string Admin::createContest(string title, string task, time_t deadline) {
    Contest contest(title, task, deadline);
    contests.insert(std::pair<string, Contest>(contest.getContestId(), contest));
    return contest.getContestId();
}

Status Admin::deleteContest(string contestId) {
    contests.erase(contestId);
    return Ok;
}
