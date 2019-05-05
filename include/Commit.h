//
// Created by horosheninad
//

#ifndef _LIB_COMMIT_H
#define _LIB_COMMIT_H

#include <fstream>
#include <iostream>
#include "Status.h"
#include <ctime>
//#include <cpprest/http_client.h>


class Commit {
private:
    string ID;
    time_t sendTime;
    string result;
    std::ifstream decision;

public:
    Commit();

    Commit(const Commit &c) {};

    ~Commit() = default;

    string getCommitId();

    Status loadFile(const char *file_name);

    Status setId(string id);

    //private:
    Status verify();
};

#endif //_LIB_COMMIT_H