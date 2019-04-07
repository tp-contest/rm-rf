//
// Created by d on 07.04.19.
//

#ifndef PRJ_DOCUMENT_H
#define PRJ_DOCUMENT_H

#include "DocumentState.h"
#include "time.h"

class Document {
private:
    DocumentState state;
    int ID;
    time_t startTime;
    time_t endTime;

public:
    virtual void saveDocument();
    virtual void fixDocument();
    virtual void deleteDocument();
};


#endif //PRJ_DOCUMENT_H
