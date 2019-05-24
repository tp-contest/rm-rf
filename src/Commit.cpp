//
// Created by horosheninad on 09.04.2019.
//

#include "Commit.h"

string Commit::getCommitId() {
    return this->ID;
}

Status Commit::setId(string id) {
    this->ID = id;
    return OK;
}