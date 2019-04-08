//
// Created by d on 07.04.19.
//

#include "../include/Document.h"

void Document::setState(const DocumentState &state) {
    Document::state = state;
}

void Document::setId(int id) {
    ID = id;
}

void Document::setStartTime(time_t startTime) {
    Document::startTime = startTime;
}

void Document::setEndTime(time_t endTime) {
    Document::endTime = endTime;
}
