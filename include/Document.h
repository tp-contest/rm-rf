//
// Created by d on 07.04.19.
//

#ifndef PRJ_DOCUMENT_H
#define PRJ_DOCUMENT_H

#include <iostream>
#include <fstream>
#include "DocumentState.h"
#include "DraftState.h"
#include "Status.h"
#include "time.h"
#include "DeletedState.h"
#include <sstream>

using std::string;
using std::ifstream;
using std::stringstream;

class Document {

protected:
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
    Document() : ID(-1), name(""), state(nullptr), file(nullptr) {};
    ~Document() {
        delete file;
    };

    int getId() const {
        return ID;
    };


    Status editFile() {
        state->editDocument();
    }

    Status saveDocument() {
        state->saveDocument();
        calculateId();
    }

    Status deleteFile() {
        state->deleteDocument();

        delete state;
        state = new DeletedState();

        if (!file)
            return ERROR;
        ID = -1;
        name = "";
        state = nullptr;
        delete file;
        file = nullptr;
        return OK;
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
        state = new DraftState();

        return OK;
    };

    char * getFile() {
        return file;
    }

};


#endif //PRJ_DOCUMENT_H
