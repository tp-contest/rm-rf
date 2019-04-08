//
// Created by d on 08.04.19.
//

#ifndef PRJ_DOCUMENTSTATE_H
#define PRJ_DOCUMENTSTATE_H

#include <iostream>

class DocumentState {
public:
    DocumentState() {};
    ~DocumentState() {};
    virtual bool saveDocument() = 0;
    virtual bool editDocument() = 0;
    virtual bool deleteDocument() = 0;
};

#endif //PRJ_DOCUMENTSTATE_H
