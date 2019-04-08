//
// Created by horosheninad
//

#ifndef _LIB_COMMIT_H
#define _LIB_COMMIT_H

#include <iostream>
#include <string>

using std::string;

class Commit {
private:
    string ID;
    time_t sendTime;
    string result;
public:
    Commit() {};
    Commit(time_t sendTime) : sendTime(sendTime) {};
    ~Commit() {};
    string getCommitId() {
        return this->ID;
    }
};

#endif //_LIB_COMMIT_H
