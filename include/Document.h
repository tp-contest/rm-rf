//
// Created by d on 07.04.19.
//

#ifndef PRJ_DOCUMENT_H
#define PRJ_DOCUMENT_H

#include <iostream>
#include "time.h"
#include "DocumentState.h"

class Document {
private:
    DocumentState * state;
    int ID;
    std::string info;
    time_t startTime;
    time_t endTime;
    FILE * file; // to vector

public:
    Document();
    ~Document();
    virtual void saveDocument() {
        state->saveDocument();
    };
    void setState(DocumentState & docstate) {
        state = &docstate;
    }

    virtual void editDocument() {};
    virtual void deleteDocument() {};

    int calculateId();

    void setId(int id);
    void setStartTime(time_t start);
    void setEndTime(time_t end);

    bool loadFormPath(std::string path) {
        return true;
    };
    int getId() const;
    std::string getInfo() const;
    time_t getStartTime() const;
    time_t getEndTime() const;

    DocumentState * getState() {
        return state;
    }
};


#endif //PRJ_DOCUMENT_H
