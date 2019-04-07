//
// Created by yu on 07.04.19.
//

#include "../../src/Person.h"
#include "gtest/gtest.h"

namespace  {
    class Test_Person : public ::testing::Test {
    public:
        Person person_;
    };

    TEST_F(Test_Person, authorization) {
        std::string login = "Goshan";
        std::string password = "123456";
        bool expected_result = true;

        bool result = person_.authorization(login, password);
        EXPECT_EQ(result, expected_result);
    }

}