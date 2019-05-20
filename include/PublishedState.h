//
// Created by d on 07.04.19.
//

#ifndef PRJ_PUBLISHEDSTATE_H
#define PRJ_PUBLISHEDSTATE_H

#include "DocumentState.h"

class PublishedState: public DocumentState {
public:
    PublishedState() {};
    ~PublishedState() {};

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

#endif //PRJ_PUBLISHEDSTATE_H
