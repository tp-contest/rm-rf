//
// Created by horosheninad
//

#include <iostream>
#include <gtest/gtest.h>
#include "../include/Contest.h"
#include "assert.h"

TEST(ContestTest, contestTest) {
    //ASSERT_NE(NULL, Contest());
}

TEST(AdminTest, registration) {
    Contest contest = Contest("My contest", "do this please", 100);
    if (contest.editTitle("no no no!")) {
        string title = contest.getTitle();
        EXPECT_EQ(title, "no no no!");
    }
}