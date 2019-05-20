//
// Created by d on 20.05.19.
//

#ifndef PRJ_DELETEDSTATE_H
#define PRJ_DELETEDSTATE_H

#include "DocumentState.h"

class DeletedState: public DocumentState {
public:
    DeletedState() {};
    ~DeletedState() {};

    Status saveDocument(Document * doc) override {
        return ERROR;
    };

    Status editDocument(Document * doc) override {
        return ERROR;
    };

    Status deleteDocument(Document * doc) override {
        return ERROR;
    };
};

#endif //PRJ_DELETEDSTATE_H
