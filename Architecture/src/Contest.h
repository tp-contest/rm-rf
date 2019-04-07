#ifndef MYPROJECT_CONTEST_H
#define MYPROJECT_CONTEST_H

#include <string>
#include <list>

#include "Commit.h"

using std::list;


class Contest {
private:
    int ID;
    string Title;
    time_t deadline;
    string Task;
    int timeLimit;
    int memoryLimit;
    list<Commit> attempts;
public:
    Contest(string Title);
    ~Contest();
    bool changeTask(string Task);
    bool changeLimits(int timeLimit, int memoryLimit);
    bool changeDeadline(time_t deadline);
    bool addCommit(Commit newAttempt);
};


#endif //MYPROJECT_CONTEST_H
