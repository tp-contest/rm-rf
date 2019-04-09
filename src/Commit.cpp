//
// Created by horosheninad on 09.04.2019.
//

#include "../include/Commit.h"
#include <string>

string Commit::getCommitId() {
    return this->ID;
}

status Commit::setId(string id) {
    this->ID = id;
    return 101;
}