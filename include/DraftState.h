//
// Created by d on 07.04.19.
//

#ifndef PRJ_DRAFTSTATE_H
#define PRJ_DRAFTSTATE_H

#include "DocumentState.h"
//#include "Document.h"

class DraftState: public DocumentState{
private:
   // Document * document;
public:
    DraftState() {
    }
    /*DraftState(Document & doc) {
        document = &doc;
        std::cout << "draft constructor" << std::endl;
    };*/
    ~DraftState(){

    };
    Status saveDocument() override {
        std::cout << "draft saving" << std::endl;
        return ERROR;
    }
    Status editDocument() override {
        return ERROR;
    };
    Status deleteDocument() override {
        return ERROR;
    };
};


#endif //PRJ_DRAFTSTATE_H
