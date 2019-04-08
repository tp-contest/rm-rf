//
// Created by d on 07.04.19.
//

#ifndef PRJ_DRAFTSTATE_H
#define PRJ_DRAFTSTATE_H

#include "DocumentState.h"
#include "Document.h"

class DraftState: public DocumentState{
private:
    Document * document;
public:
    DraftState() {
    }
    DraftState(Document & doc) {
        document = &doc;
        std::cout << "draft constructor" << std::endl;
    };
    ~DraftState(){

    };
    void saveDocument() override {
        std::cout << "draft saving" << std::endl;
    }
    void editDocument() override {

    };
    void deleteDocument() override {

    };
};


#endif //PRJ_DRAFTSTATE_H
