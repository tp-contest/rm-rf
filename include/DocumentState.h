//
// Created by d on 08.04.19.
//

#ifndef PRJ_DOCUMENTSTATE_H
#define PRJ_DOCUMENTSTATE_H

#include <iostream>
#include "Status.h"


class Document;
class DocumentState {
protected:
    Document * document;
public:
    DocumentState() {};
    ~DocumentState() {};

    virtual Status saveDocument(Document * doc) = 0;
    virtual Status editDocument(Document * doc) = 0;
    virtual Status deleteDocument(Document * doc) = 0;
};

#endif //PRJ_DOCUMENTSTATE_H
