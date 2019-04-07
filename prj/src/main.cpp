#include <iostream>
#include <gtest/gtest.h>
#include "../include/Subscriber.h"


TEST(SuiteName, TestName) {
    Subscriber sbsc = Subscriber();
    EXPECT_EQ(1, sbsc.getValue());
}