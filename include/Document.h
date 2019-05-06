//
// Created by d on 07.04.19.
//

#ifndef PRJ_DOCUMENT_H
#define PRJ_DOCUMENT_H

#include <iostream>
#include "time.h"
#include "DocumentState.h"
#include "Status.h"
#include <experimental/filesystem>
#include <fstream>

#define MIN_SIZE 1
#define MAX_SIZE 1000000

class Document {
private:
    DocumentState * state;
    int ID;
    std::ifstream* file;

public:
    Document();
    ~Document() = default;
    virtual void saveDocument() {
        state->saveDocument();
    };
    void setState(DocumentState & docstate) {
        state = &docstate;
    }

    virtual void editDocument() {};
    virtual void deleteDocument() {};

    void setId(int id);
    int getId() const;

    DocumentState * getState() {
        return state;
    }

    Status loadFile(const char *file_name);
    Status verify(const std::experimental::filesystem::path &file) const;

};


#endif //PRJ_DOCUMENT_H
