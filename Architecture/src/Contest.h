#ifndef MYPROJECT_CONTEST_H
#define MYPROJECT_CONTEST_H

#include <map>
#include "status.h"
#include "Commit.h"

using std::map;

class Contest {
private:
    string ID_;
    string title_;
    time_t deadline_;
    string task_;
    int timeLimit_;
    int memoryLimit_;
    map<string, Commit> commits_;
public:
    Contest(string title);

    ~Contest();

    status editTitle(string title);

    status editTask(string Task);

    status changeLimits(int timeLimit, int memoryLimit);

    status editDeadline(time_t deadline);

    status addCommit(const Commit &newCommit);

    string getContestId();
};


#endif //MYPROJECT_CONTEST_H
