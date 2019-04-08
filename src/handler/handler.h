//
// Created by horosheninad
//

#ifndef _LIB_HANDLER_H
#define _LIB_HANDLER_H

class Handler {
public:
    Handler() {}
    ~Handler() {};
    // todo:: status
    int getStatUsersByContest(std::string contestId) {
        return 200;
    }
    int getStatContest(std::string contestId) {
        return 200;
    }
    int showContestByUser(std::string userId) {
        return 200;
    }
    int showUsersCommitsByContest(std::string contestId) {
        return 200;
    }
    int openUserCodeFromLastCommit(std::string contestId) {
        return 200;
    }
};
#endif //_LIB_HANDLER_H
