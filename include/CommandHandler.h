//
// Created by d on 07.04.19.
//

#ifndef PRJ_COMMANDHANDLER_H
#define PRJ_COMMANDHANDLER_H

#include <vector>
#include "Document.h"
#include "Handler.h"
#include "Publisher.h"

class CommandHandler: public Handler {
private:
    Publisher * publisher;
    std::vector<Document *> documents;
public:
    CommandHandler() {};
    ~CommandHandler() {};
    void pushToServer(const std::string & mess) override {

    };
    void getInfo() override {
        std::cout << "COMMAND HANDLER GET INFO" << std::endl;
    };
    void addDocument(const Document & document) {
    };
    void editDocument(int ID) {
    };
    void deleteDocument(int ID) {
    };
    void pushDocument(int ID) {
    };

    int getDocumentNumber() {
        return documents.size();
    }

    int getStatUsersByContest(std::string contestId) {
        return 0;
    };
    int getStatContest(std::string contestId) {
        return 0;
    };
    int showContestByUser(std::string userId) {
        return 0;
    };
    int showUsersCommitsByContest(std::string contestId) {
        return 0;
    };
    int openUserCodeFromLastCommit(std::string contestId) {
        return 0;
    };

};



#endif //PRJ_COMMANDHANDLER_H
