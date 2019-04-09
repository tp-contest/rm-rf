//
// Created by horosheninad
//

#ifndef _LIB_CONTEST_H
#define _LIB_CONTEST_H

#include <string>
#include <map>
#include "Commit.h"

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
    Contest(string title);
    Contest(string title, string task, time_t deadline) : title(title), task(task), deadline(deadline);
    ~Contest() {};

    bool editTitle(string title);

    bool editDeadline(time_t deadline);

    bool editTask(string task);

    status changeTask(string Task) { return 101; };
    status changeLimits(int timeLimit, int memoryLimit) { return 101; };
    status changeDeadline(time_t deadline) { return 101; };
    status addCommit(Commit& commit);
    string getContestId() {
        return this->ID;
    }
    string getTitle() {
        return this->title;
    }
};

#endif //_LIB_CONTEST_H
