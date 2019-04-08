//
// Created by Sanya on 08.04.2019.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../src/admin/admin.h"
#include "assert.h"

TEST(AdminSuite, costructorTest) {
    //ASSERT_NE(NULL, Subscriber());
}

TEST(Admin, registration) {
    Admin ad = Admin();
    ad.registration("sanya", "sanya23125", "1111");
}

TEST(Admin, changePassword) {
    Admin ad = Admin();
    ad.changePassword("123", "211");
}