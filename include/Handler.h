//
// Created by d on 07.04.19.
//

#ifndef PRJ_HANDLER_H
#define PRJ_HANDLER_H

#include <string>

class Handler {
private:
    bool readyDataBit = false;
public:
    Handler() {};
    ~Handler() {};
    virtual void pushToServer(const std::string & mess) = 0;
    virtual void getInfo() = 0;

    virtual int getStatUsersByContest(std::string contestId) = 0;
    virtual int getStatContest(std::string contestId)= 0;
    virtual int showContestByUser(std::string userId) = 0;
    virtual int showUsersCommitsByContest(std::string contestId)= 0;
    virtual int openUserCodeFromLastCommit(std::string contestId) = 0;
};


#endif //PRJ_HANDLER_H
