#include "../include/Commit.h"

//using namespace boost::filesystem;

Commit::Commit() {
    string from_server = "from server";
    setId(from_server);
    sendTime = std::time(nullptr);
    result = "Not sent";
}

string Commit::getCommitId() {
    return this->ID;
}

Status Commit::setId(const string &id) {
    this->ID = id;
    return Ok;
}

Status Commit::Add(const std::vector<const char *> &paths) {
    for (auto& path:paths){
        auto *new_doc = new Document();
        if (new_doc->loadFile(path) != Ok){
            return ERROR;
        }
        decision.push_back(new_doc);
    }
    return Ok;
}
