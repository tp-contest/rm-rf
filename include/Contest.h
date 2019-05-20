//
// Created by horosheninad
//

#ifndef _LIB_CONTEST_H
#define _LIB_CONTEST_H

#include <string>
#include <map>
#include "Commit.h"
#include "Status.h"
#include "Document.h"

using std::map;

class Contest : public Document  {
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
    Contest(string title, string task, time_t deadline) : title(title), task(task), deadline(deadline) {
        this->ID = '1'; // tools.GenerateUUID();
    };
    ~Contest() {};

    bool editTitle(string title);

    bool editDeadline(time_t deadline);

    bool editTask(string task);

    Status changeTask(string Task) { return Ok; };

    Status changeLimits(int tLimit, int mLimit) { return Ok; };
    Status changeDeadline(time_t deadline) { return Ok; };
    Status addCommit(Commit& commit);
    string getContestId() {
        return this->ID;
    }
    string getTitle() {
        return this->title;
    }

    bool isEmptyCommits() {
        return commits.empty();
    }
};

#endif //_LIB_CONTEST_H
