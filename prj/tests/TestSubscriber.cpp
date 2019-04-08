//
// Created by d on 08.04.19.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../include/Subscriber.h"
#include "assert.h"

TEST(SubscriberSuite, costructorTest) {
    //ASSERT_NE(NULL, Subscriber());
}

TEST(SubscriberSuite, handleServerAnswerTest1) {
    Subscriber sbsc = Subscriber();
    const std::string str;
    sbsc.handleServerAnswer(str);
}

TEST(SubscriberSuite, handleServerAnswerTest2) {
    Subscriber sbsc = Subscriber();
    sbsc.handleServerAnswer(nullptr);
}