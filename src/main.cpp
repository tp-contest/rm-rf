#include <iostream>
#include "../include/Document.h"
#include "../include/DraftState.h"
#include "../include/UserFile.h"
#include "../include/Publisher.h"
#include "../include/Subscriber.h"
#include "../include/JsonParser.h"

#include "gtest/gtest.h"
#include "../include/NoUserHandler.h"
#include "../include/UserHandler.h"
#include "../include/AdminHandler.h"
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

    User * user = nullptr;
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

    delete noUserHandler;
    delete userHandler;
    delete adminHandler;
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