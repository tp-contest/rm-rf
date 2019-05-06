//
// Created by horosheninad
//

#ifndef _LIB_CONTEST_H
#define _LIB_CONTEST_H

#include <string>
#include <map>
#include "Commit.h"
#include "../include/Status.h"

using std::map;

class Contest {
private:
    string ID;
    string title_;
    time_t deadline_;
    string task_;
    int timeLimit;
    int memoryLimit;
    map<string, Commit> commits;
public:
    Contest(const string &name);

    ~Contest() = default;

    Status editTitle(const string &new_title);

    Status editDeadline(time_t deadline);

    Status editTask(const string &task);

    Status changeTask(string Task);

    Status changeLimits(int timeLimit, int memoryLimit);

    Status changeDeadline(time_t deadline);

    Status addCommit(Commit &commit);

    string getContestId();

    string getTitle();
};

#endif //_LIB_CONTEST_H
