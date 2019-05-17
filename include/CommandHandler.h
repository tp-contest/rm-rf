//
// Created by d on 07.04.19.
//

#ifndef PRJ_COMMANDHANDLER_H
#define PRJ_COMMANDHANDLER_H

#include <vector>
#include <map>
#include "Document.h"
#include "Handler.h"
#include "Publisher.h"
#include "User.h"

class CommandHandler: public Handler {
public:
    CommandHandler() {};
    ~CommandHandler() {};

    bool addDocument(const std::string pathToFile) {

        // open files //
        Document * document = new Document();

    };

};

/*class CommandHandler: public Handler {
private:
    User * user;
    Publisher * publisher;
    std::vector<Document *> documents;

public:
    CommandHandler(): user(nullptr), publisher(new Publisher()) {
    };

    ~CommandHandler() {
        if (user) {
            delete user;
        }
        if (publisher) {
            delete publisher;
        }
    };
    void pushToServer(const std::string & mess) override {

    };
    void getInfo() override {
        std::cout << "COMMAND HANDLER GET INFO" << std::endl;
    };

    bool addDocument(const std::string pathToFile) {
        if (!user)
            return false;

        // open files //
        Document * document = new Document()

    };

    void editDocument(int ID) {

    };
    void deleteDocument(int ID) {
    };
    void getDocument(int ID) {
    };

    // TODO: add publisher and server connection
    void pushDocument(int ID) {

    };

    void getDocumetList() {
        if (!documents.size()) {
            std::cout << "No documents yet" << std::endl;
        }

        for (int i = 0; i < documents.size(); i++) {
            std::cout << documents[i]->getInfo() << ": " << documents[i]->getStartTime() << std::endl;
        }
    }
    int getDocumentNumber() {
        return documents.size();
    }
}*/



#endif //PRJ_COMMANDHANDLER_H
