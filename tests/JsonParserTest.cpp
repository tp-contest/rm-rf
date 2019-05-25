//
// Created by alex on 05.05.2019.
//

#include "gtest/gtest.h"
#include "../includes/JsonParser.h"

TEST(JsonParser, FromNull){
    JsonParser::JsonParser json(nullptr);
    ASSERT_EQ("null", json.ToString());
}

TEST(JsonParser, ToNull){
    const auto  json = JsonParser::JsonParser::FromString(nullptr);
    ASSERT_TRUE(json == nullptr);
}

TEST(JsonParser, FromBolean){
    JsonParser::JsonParser jsonTrue(true), jsonFalse(false);
    ASSERT_EQ("true", jsonTrue.ToString());
    ASSERT_EQ("false", jsonFalse.ToString());
}

TEST(JsonParser, ToBolean){
    const auto  jsonTrue = JsonParser::JsonParser::FromString("true");
    const auto  jsonFalse = JsonParser::JsonParser::FromString("false");
    ASSERT_TRUE(jsonTrue == true);
    ASSERT_TRUE(jsonFalse == false);
}

TEST(JsonParser, FromSomeString){
    JsonParser::JsonParser json("Hello, World!");
    ASSERT_EQ("\"Hello, World\"", json.ToString());
}

TEST(JsonParser, ToSomeString){
    const auto  json = JsonParser::JsonParser::FromString("\"Hello, World!\"");
    ASSERT_TRUE(json == std::string("Hello, World!"));
}

TEST(JsonParser, EscapingChar){
    JsonParser::JsonParser json(std::string("This should be escaped: \", \\, \b, \f,  \n, \r, \t"));
    ASSERT_EQ("\"These should be escaped: \\\", \\\\, \\b, \\f, \\n, \\r, \\t\"", json.ToString());
}


//Not finished
/* TEST(JsonParser, DecodeObject) {
    const std::string encoding("{\"ServerResponse\": 400, \"\": \"SessionID\":37}");
    const auto json = JsonParser::JsonParser::FromEncoding(encoding);
    ASSERT_EQ(Json::JsonParser::Type::Object, json.GetType());
    ASSERT_EQ(2, json.GetSize());
    const auto value = json["value"];
    EXPECT_EQ(JsonParser::JsonParser::Type::Integer, value.GetType());
    EXPECT_EQ(42, (int)value);
    const auto empty = json[""];
    EXPECT_EQ(Json::JsonParser::Type::String, empty.GetType());
    EXPECT_EQ("SessionID", (std::string)empty);
    EXPECT_EQ(Json::JsonParser::Type::Integer, SessionID.GetType());
    ASSERT_EQ(37, (int)SessionID);
}*/

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
