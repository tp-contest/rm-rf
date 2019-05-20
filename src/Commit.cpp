//
// Created by horosheninad on 09.04.2019.
//

#include "../include/Commit.h"
#include "../include/Status.h"
#include <string>

string Commit::getCommitId() {
    return this->ID;
}

Status Commit::setId(string id) {
    this->ID = id;
    return OK;
}