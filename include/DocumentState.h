//
// Created by d on 08.04.19.
//

#ifndef PRJ_DOCUMENTSTATE_H
#define PRJ_DOCUMENTSTATE_H

#include <iostream>
#include "Status.h"

class DocumentState {
public:
    DocumentState() {};
    ~DocumentState() {};
    virtual Status saveDocument() = 0;
    virtual Status editDocument() = 0;
    virtual Status deleteDocument() = 0;
};

#endif //PRJ_DOCUMENTSTATE_H
