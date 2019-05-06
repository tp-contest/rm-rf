//
// Created by horosheninad
//

#ifndef _LIB_COMMIT_H
#define _LIB_COMMIT_H

#include <fstream>
#include <iostream>
#include "Status.h"
#include <vector>
#include <ctime>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
//#include <boost/filesystem.hpp>
#include <experimental/filesystem>
#include "Document.h"

class Commit {
private:
    string ID;
    time_t sendTime;
    string result;
    std::vector<Document*> decision;

public:
    Commit();

    Commit(const Commit &c) = default;

    ~Commit() = default;

    string getCommitId();

    Status Add(const std::vector<const char *> &paths);

    Status setId(const string &id);
};

#endif //_LIB_COMMIT_H