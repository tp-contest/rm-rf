//
// Created by horosheninad
//

#ifndef _LIB_CONTEST_H
#define _LIB_CONTEST_H

#include <string>
#include <map>
#include "../commit/Commit.h"

using std::map;

//TODO:: create enum status list
typedef int status;

class Contest {
private:
    string ID;
    string title;
    time_t deadline;
    string task;
    int timeLimit;
    int memoryLimit;
    map<string, Commit> commits;
public:
    Contest(string title) {
        this->ID = '1'; // tools.GenerateUUID();
    };
    Contest(string title, string task, time_t deadline) : title(title), task(task), deadline(deadline) {
        this->ID = '1'; // tools.GenerateUUID();
    };
    ~Contest() {};

    bool editTitle(string title) {
        if (title == "") {
            return false;
        }
        this->title = title;
        return true;
    };

    bool editDeadline(time_t deadline) {
        if (deadline < 0) {
            return false;
        }
        this->deadline = deadline;
        return true;
    };

    bool editTask(string task) {
        if (task == "") {
            return false;
        }
        this->task = task;
        return true;
    };

    status changeTask(string Task) { return 101; };
    status changeLimits(int timeLimit, int memoryLimit) { return 101; };
    status changeDeadline(time_t deadline) { return 101; };
    status addCommit(Commit& commit) {
        commits.insert(std::pair<string, Commit>(commit.getCommitId(), commit));
        return 101;
    };
    string getContestId() {
        return this->ID;
    }
};

#endif //_LIB_CONTEST_H
