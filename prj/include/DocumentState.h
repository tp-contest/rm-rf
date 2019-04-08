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
    virtual void saveDocument() {
        std::cout << "hello saving" << std::endl;
    };
    virtual void editDocument() {};
    virtual void deleteDocument() {};
};

#endif //PRJ_DOCUMENTSTATE_H
