//
// Created by d on 07.04.19.
//

#ifndef PRJ_DOCUMENT_H
#define PRJ_DOCUMENT_H

#include <iostream>
#include <fstream>
#include "DocumentState.h"
#include "DraftState.h"
#include "PublishedState.h"
#include "Status.h"
#include "time.h"
#include "DeletedState.h"
#include <sstream>

using std::string;
using std::ifstream;
using std::stringstream;

class Document {
    friend class DocumentState;
    friend class DraftState;
    friend class DeletedState;
    friend class PublishedState;

private:
    int ID;
    string name;
    DocumentState * state;
    char * file;

    void calculateId() {
        int s = 1000; // TODO: fix s param
        int len = name.length();
        ID = name[len - 1];
        int x0 = 7;
        for (int i = len - 2; i >= 0; i--) {
            ID = name[i] + ID * x0;
        }
        ID = ID % s;
    };

public:

    Document() : ID(-1), name(""), file(nullptr) {
        state = new DraftState();
    };

    Document(std::string path) {
        calculateId();
        loadFromPath(path);
    }

    ~Document() {
        delete file;
        delete state;
    };

    Status editDocument() {
        state->editDocument(this);
    }

    Status saveDocument() {
        state->saveDocument(this);
    }

    Status deleteDocument() {
        state->deleteDocument(this);

        delete state;
        state = new DeletedState();

        /*if (!file)
            return ERROR;
        ID = -1;
        name = "";
        state = nullptr;
        delete file;
        file = nullptr;
        return OK;*/
    }

    Status loadFromPath(std::string path) {
        if (file) {
            return ERROR;
        }

        name = path;
        std::ifstream infile(path);
        if (!infile) {
            return ERROR;
        }

        infile.seekg(0, infile.end);
        size_t length = infile.tellg();
        infile.seekg(0, infile.beg);

        file = new char[length];
        if (!file) {
            return ERROR;
        }

        infile.read(file, length);

        return OK;
    };

    char * getFile() {
        return file;
    }

    void setPublishState() {
        delete state;
        state = new PublishedState;
    }

    void setDeletedState() {
        delete state;
        state = new DeletedState;
    }

    void setDraftState() {
        delete state;
        state = new DraftState;
    }

    int getID() {
        return ID;
    }

};


#endif //PRJ_DOCUMENT_H
