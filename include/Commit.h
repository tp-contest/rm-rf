//
// Created by horosheninad
//

#ifndef _LIB_COMMIT_H
#define _LIB_COMMIT_H

#include <fstream>
#include <iostream>
#include "Status.h"
#include <ctime>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <boost/filesystem.hpp>


#define MIN_SIZE 1
#define MAX_SIZE 100000

class Commit {
private:
    string ID;
    time_t sendTime;
    string result;
    //std::ifstream decision;
    std::string file_name_;

public:
    Commit();

    Commit(const Commit &c) = default;

    ~Commit() = default;

    string getCommitId();

    Status loadFile(const char *file_name);

    Status setId(string id);

private:
    Status verify();
};

#endif //_LIB_COMMIT_H