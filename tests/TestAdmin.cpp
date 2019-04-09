//
// Created by Sanya on 08.04.2019.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../include/Admin.h"
#include "assert.h"

TEST(AdminTest, costructorTest) {
    //ASSERT_NE(NULL, Admin());
}

TEST(AdminTest, registration) {
    Admin ad = Admin();
    int a = ad.registration("sanya", "sanya23125", "1111");
    EXPECT_EQ(a, 101);
}

TEST(AdminTest, changePassword) {
    Admin ad = Admin();
    int a = ad.changePassword("123", "211");
    EXPECT_EQ(a, 101);
}

TEST(AdminTest, authorization) {
    Admin ad = Admin();
    ad.setSessionId("123");
    int a = ad.authorization();
    EXPECT_EQ(a, 101);
}

TEST(AdminTest, createContest) {
    Admin ad = Admin();
    ad.setSessionId("123");
    string a = ad.createContest("1","2",10);
    EXPECT_EQ(a, "1");
}

TEST(AdminTest, editContest) {
    Admin ad = Admin();
    ad.setSessionId("123");
    int a = ad.editContest("1","1","2",10);
    EXPECT_EQ(a, 101);
}

TEST(AdminTest, getStatUsersByContest) {
    Admin ad = Admin();
    ad.setSessionId("123");
    int a = ad.getStatUsersByContest("1");
    EXPECT_EQ(a, 101);
}
