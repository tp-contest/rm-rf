//
// Created by d on 07.04.19.
//

#ifndef PRJ_DRAFTSTATE_H
#define PRJ_DRAFTSTATE_H

#include "DocumentState.h"

class DraftState: public DocumentState{
    friend class Document;
public:
    ~DraftState(){};
    DraftState() {};

    Status saveDocument(Document * doc) override {
        return ERROR;
    }
    Status editDocument(Document * doc) override {
        return ERROR;
    };

    Status deleteDocument(Document * doc) override {
        return ERROR;
    };
};

#endif //PRJ_DRAFTSTATE_H
