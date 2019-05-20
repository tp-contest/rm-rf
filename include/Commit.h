//
// Created by horosheninad
//

#ifndef _LIB_COMMIT_H
#define _LIB_COMMIT_H

#include <iostream>
#include <string>
#include "../include/Status.h"

//TODO:: create enum status list
typedef int status;

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
    string getCommitId();
    Status setId(string id);

    Status loadFile(const char *file_name) { return OK; };

    Status verify() { return OK; };
};

#endif //_LIB_COMMIT_H
