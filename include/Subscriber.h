//
// Created by d on 07.04.19.
//

#ifndef PRJ_SUBSCRIBER_H
#define PRJ_SUBSCRIBER_H

#include "ISubscriber.h"
//#include "Handler.h"
#include "Parser.h"
#include "Status.h"
#include "Commit.h"
#include "iostream"

typedef struct {
} StatContest;

typedef struct {
} StatUsers;

typedef struct {
} StatCommit;

class Subscriber : public ISubscriber {
private:
    //Handler * handler;
    Parser * parser;
    bool checkAnswer(const std::string & answer);

    StatContest *stat;
    StatCommit *commits;

public:
    Subscriber() : parser(nullptr){};
    Subscriber( Parser & prsr) {
        parser = &prsr;
    }
    ~Subscriber() override {};

    void handleServerAnswer(const std::string & answer) override {
        if ( answer.c_str() != nullptr) {
            //handler->getInfo();
            std::cout << answer << std::endl;
        }
    };

    /*Handler * getHandler() {
        return handler;
    }*/

    Parser * getParser() {
        return parser;
    }

    Status SendToServerAuth(const string &sessionId) {
        return Ok;
    }
    Status SendToServerReg(const string &newName, const string &newLogin, const string &newPassword) {
        return Ok;
    }
    Status SendToServerRename(const string &renameField) {
        return Ok;
    }
    Status SendToServerLogout() {
        return Ok;
    }
    Status SendToServerChangePass(const string &newPass) {
        return Ok;
    }

    StatContest *GetStatUserByContest(const string &contestID) {
        return stat;
    }

    StatContest *GetStatContest(const string &contestID) {
        return stat;
    }

    StatContest *ShowContestByUser(const string &userID) {
        return stat;
    }

    StatCommit *ShowCommits(const string &contestID) {
        return commits;
    }

    string OpenUserCodeForLastCommit(const string &contestID) {
        // get user code
        return "";
    }

    Status SendCommit(const Commit &commit) {
        return Ok;
    }
};


#endif //PRJ_SUBSCRIBER_H
