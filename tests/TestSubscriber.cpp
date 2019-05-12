//
// Created by d on 08.04.19.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../include/Subscriber.h"
#include "../include/Handler.h"
#include "../include/Parser.h"
#include "../include/CommandHandler.h"
#include "assert.h"
#include "../include/JsonParser.h"


/*TEST(SubscriberSuite, costructorTest) {
    Subscriber * subscriber = new Subscriber();
    ASSERT_NE(nullptr, subscriber);
    Handler * handler = subscriber->getHandler();
    ASSERT_EQ(nullptr, handler);
    Parser * parser = subscriber->getParser();
    ASSERT_EQ(nullptr, parser);
}

TEST(SubscriberSuite, handleServerAnswerTest1) {
    CommandHandler cmdhandl = CommandHandler();
    JsonParser parser = JsonParser();
    Subscriber * sbsc = new Subscriber(cmdhandl, parser);
    const std::string str = "HELLO";
    sbsc->handleServerAnswer(str);
}

TEST(SubscriberSuite, handleServerAnswerTest2) {
    Subscriber sbsc = Subscriber();
    const std::string str = "HELLO";
    sbsc.handleServerAnswer(str);
}*/
