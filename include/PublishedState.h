//
// Created by d on 07.04.19.
//

#ifndef PRJ_PUBLISHEDSTATE_H
#define PRJ_PUBLISHEDSTATE_H

#include "Document.h"

class PublishedState: public DocumentState {
public:
    PublishedState() {};
    ~PublishedState() {};

    Status saveDocument() override {

    };
    Status editDocument() override {

    };
    Status deleteDocument() override {

    };
};

#endif //PRJ_PUBLISHEDSTATE_H
