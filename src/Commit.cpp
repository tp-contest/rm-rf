#include "../include/Commit.h"

using namespace boost::filesystem;

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
    file_name_ = file_name;
    path file{file_name_};
    boost::system::error_code ec;
    boost::uintmax_t filesize = file_size(file, ec);
    if (ec)
        return ERROR;

    /*decision.open(file_name, std::ios::in);
    return verify();*/
}

Status Commit::verify() {

    /*if (!decision.is_open())
        return ERROR;
    decision.seekg(0, std::ios::end);
    int size = decision.tellg();
    decision.seekg(0, std::ios::beg);
    if (size < MIN_SIZE || size > MAX_SIZE) {
        return ERROR;
    }*/
}