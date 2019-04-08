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

    void setId(int id);
    void setStartTime(time_t startTime);
    void setEndTime(time_t endTime);

    int getId() const;
    time_t getStartTime() const;
    time_t getEndTime() const;
};


#endif //PRJ_DOCUMENT_H
