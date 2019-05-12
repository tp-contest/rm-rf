//#define private public

#include "../../src/User.h"
#include "gtest/gtest.h"
#include "../../src/status.h"

using std::string;

namespace {
    class Test_User : public ::testing::Test {
    protected:
        User user_;
    };

    status expected_result = OK;

    TEST_F(Test_User, authorization) {
        string login = "Goshan";
        string password = "123456";
        status result = user_.authorization(login, password);
        EXPECT_EQ(result, expected_result);
    }

    TEST_F(Test_User, registration) {
        string login = "Goshan";
        string password = "123456";
        string name = "Hacker";

        status result = user_.registration(name, login, password);
        EXPECT_EQ(result, expected_result);
    }

    TEST_F(Test_User, logout) {
        status result = user_.logout();
        EXPECT_EQ(result, expected_result);
    }

    TEST_F(Test_User, rename) {
        string name = "Hacker";

        status result = user_.rename(name);
        EXPECT_EQ(result, expected_result);
    }

    TEST_F(Test_User, changePassword) {
        string password = "123456";
        status result = user_.changePassword(password, password + "1");
        EXPECT_EQ(result, expected_result);
    }

    TEST_F(Test_User, applyForContest) {
        string title = "first";
        Contest c(title);
        status result = user_.applyForContest(c);
        EXPECT_EQ(result, expected_result);
    }

    TEST_F(Test_User, sendCommit) {
        string contestID = "001";
        status result = user_.sendCommit(contestID);
        EXPECT_EQ(result, expected_result);
    }
}
