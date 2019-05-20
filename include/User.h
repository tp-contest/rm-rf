#ifndef PRJ_USER_H
#define PRJ_USER_H

#include <iostream>
#include <map>
#include "Contest.h"
#include "Status.h"
#include "Document.h"
#include "Subscriber.h"

using std::map;

class User {
public:
    User(){}

    User(std::string username, std::string password): username(username), password(password), admin(false) {
        std::cout << "got user" << std::endl;
    }

    ~User(){}

    bool isAdmin(){
        return admin;
    }

    Status applyForContest(const Contest &newContest) { return OK; };
    Status sendCommit(string ContestID) { return OK; };
    Status applyForContest(Contest &newContest);

    Contest *showContestByUser(const string &userID);
    Contest *showContest(const string &contestID);

    string showResult(const string &contestID, const string &userID);
    Status sendCommit(string &ContestID, Commit &commit);
    void addContest(Contest &contest);
    void deleteContest(const string &contestID);
    string createContest(const string &title, const string &task, time_t deadline);
    Status editContest(const string &contestId, const string &title, const string &task, time_t deadline);


    Status registration(const string &newName, const string &newLogin, const string &newPassword);
    Status authorization();
    Status logout();
    Status rename(const string &renameField);
    Status changePassword(const string &oldPass, const string &newPass);
    Status setSessionId(const string &sessId);
    string getSessionId();

    Contest *getStatUsersByContest(const string &contestID);
    Contest *getStatContest(const string &contestID);
    Commit *showCommits(const string &contestID);
    string openUserCodeForLastCommit(const string &contestID) const;

private:

    string ID;
    std::string username;
    std::string password;

    bool admin;
    Subscriber * subscriber;
    map<std::string, Document> documents;
};

#endif //PRJ_USER_H

