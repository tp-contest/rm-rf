//

#include "../include/Document.h"

//
// Created by d on 07.04.19.

Document::Document() {
    std::cout << "hello doc consstr" << std::endl;
    state = nullptr;
}

Document::~Document() {

}

int Document::calculateId() {
    ID = 0;
    return ID;
};

void Document::setId(int id) {
    ID = id;
}

void Document::setStartTime(time_t startTime) {
    Document::startTime = startTime;
}

void Document::setEndTime(time_t endTime) {
    Document::endTime = endTime;
}

int Document::getId() const {
    return ID;
}

time_t Document::getStartTime() const {
    return startTime;
}

time_t Document::getEndTime() const {
    return endTime;
}
