//
// Created by horosheninad
//

#include "../include/Admin.h"

status Admin::editContest(string contestId, string title, string task, time_t deadline) {
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

status Admin::createContest(string title, string task, time_t deadline) {
    Contest contest(title, task, deadline);
    contests.insert(std::pair<string, Contest>(contest.getContestId(), contest));
    return contest.getContestId();
}

status Admin::deleteContest(string contestId) {
    contests.erase(contestId);
    return 101;
}

status Admin::getStatUsersByContest(string contestId) {
    Handler handler;
    return handler.getStatUsersByContest(contestId);
}

status Admin::getStatContest(string contestId)  {
    Handler handler;
    return handler.getStatContest(contestId);
}

status Admin::showContestByUser(string userId) {
    Handler handler;
    return handler.showContestByUser(userId);
}

status Admin::showUsersCommitsByContest(string contestId) {
    Handler handler;
    return handler.showUsersCommitsByContest(contestId);
}

status Admin::openUserCodeFromLastCommit(string commitId)  {
    Handler handler;
    return handler.openUserCodeFromLastCommit(commitId);
}