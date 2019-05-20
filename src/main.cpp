#include <iostream>
#include "Document.h"
#include "DraftState.h"
#include "UserFile.h"
#include "Publisher.h"
#include "Subscriber.h"
#include "JsonParser.h"

#include "gtest/gtest.h"
#include "NoUserHandler.h"
#include "UserHandler.h"
#include "AdminHandler.h"
#include <vector>

int main() {
    /*std::cout << "hello, world" << std::endl;

    Document document = UserFile();
    DraftState state1 = DraftState();
    DraftState state2 = DraftState(document);
    document.setState(state2);
    document.saveDocument();
    document.setState(state1);
    document.saveDocument();

    CommandHandler handler = CommandHandler();
    JsonParser parser = JsonParser();
    Subscriber subscriber = Subscriber(handler, parser);
    Publisher publisher = Publisher();
    publisher.notifySubscriber(subscriber);*/

    /* Admin admin;
    if (admin.createContest("title", "task", 0) != "") {
        std::cout << "create";
    } else {
        std::cout << "not create";
    } */

    /*User * user = nullptr;
    Handler * noUserHandler = new NoUserHandler();
    Handler * userHandler = new UserHandler();
    Handler * adminHandler = new AdminHandler();

    std::string command = "";

    std::vector<Handler *> handlers;
    handlers.push_back(noUserHandler);
    handlers.push_back(userHandler);
    handlers.push_back(adminHandler);


    while (std::cin >> command) {
        int commandId = noUserHandler->requestToId(command);
        bool result = false;
        for (int i = 0; i < handlers.size() && !result; i++) {
            result = handlers[i]->handle(commandId, user);
        }
        if (result) {
            std::cout << "OK" << std::endl;
        } else {
            std::cout << "FAIL" << std::endl;
        }
    }

    delete user;
    delete noUserHandler;
    delete userHandler;
    delete adminHandler;*/

    /*Document * document = new Document();
    document->editDocument();
    document->deleteDocument();
    document->editDocument();
    delete document;*/

    /*noUserHandler->setNext(userHandler);

    noUserHandler->signUp();
    if (!user) {
        std::cout << "lucky signup" << std::endl;
    }
    noUserHandler->logout(user);

    if (!user) {
        std::cout << "lucky logout" << std::endl;
    }*/


    //testing::InitGoogleTest();
    //RUN_ALL_TESTS();
    return 0;
}