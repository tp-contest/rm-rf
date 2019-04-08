#include <iostream>
#include "../include/Document.h"
#include "../include/DraftState.h"
#include "../include/UserFile.h"
#include "../include/Publisher.h"
#include "../include/Subscriber.h"
#include "../include/CommandHandler.h"
#include "../include/JsonParser.h"

#include "gtest/gtest.h"

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
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return 0;
}