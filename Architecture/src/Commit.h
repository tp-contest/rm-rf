#ifndef MYPROJECT_COMMIT_H
#define MYPROJECT_COMMIT_H

#include "status.h"

class Commit {

private:
    string ID_;
    time_t sendTime_;
    string result_;
public:
    Commit();

    Commit(time_t sendTime) : sendTime_(sendTime){};

    ~Commit();

    string getCommitId();

};


#endif //MYPROJECT_COMMIT_H
