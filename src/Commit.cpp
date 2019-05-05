#include "../include/Commit.h"
#include "../include/Status.h"


Commit::Commit() {
    string from_server = "from server";
    setId(from_server);
    sendTime = std::time(nullptr);
    result = "Not sent";
}

string Commit::getCommitId() {
    return this->ID;
}

Status Commit::setId(string id) {
    this->ID = id;
    return Ok;
}

Status Commit::loadFile(const char *file_name) {
    decision.open(file_name, std::ios::in);
    return verify();
}

Status Commit::verify() {
    if (!decision.is_open())
        return ERROR;
    decision.seekg(0, std::ios::end);
    int size = decision.tellg();
    decision.seekg(0, std::ios::beg);
    if (size < 1 || size > (100000)) {
        return ERROR;
    }
}