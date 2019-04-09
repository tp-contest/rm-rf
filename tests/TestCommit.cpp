//
// Created by horosheninad
//

#include <iostream>
#include <gtest/gtest.h>
#include "../include/Commit.h"
#include "assert.h"
#include <string>

TEST(CommitTest, getCommitId) {
    Commit c = Commit();
    c.setId("122333");
    string str = c.getCommitId();
    EXPECT_EQ(str, "122333");
}