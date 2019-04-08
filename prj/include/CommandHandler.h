//
// Created by d on 07.04.19.
//

#ifndef PRJ_COMMANDHANDLER_H
#define PRJ_COMMANDHANDLER_H

#include <vector>
#include "Document.h"
#include "Handler.h"

class CommandHandler: public Handler {
private:
    //Publisher * publisher;
    std::vector<Document*> documents;
public:
    CommandHandler();
    ~CommandHandler();
    void viewToDocuments();
    void pushToServer(const std::string & mess) override;
    void getInfo() override ;
};



#endif //PRJ_COMMANDHANDLER_H
