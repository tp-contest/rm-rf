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

    Status saveDocument() override {

    };

    Status editDocument() override {

    };
    Status deleteDocument() override {

    };
};

#endif //PRJ_DELETEDSTATE_H
