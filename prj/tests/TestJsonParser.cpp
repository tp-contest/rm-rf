//
// Created by d on 08.04.19.
//
#include "gtest/gtest.h"
#include "../include/JsonParser.h"


TEST(JsonParser, parseRequest) {
    JsonParser parser = JsonParser();
    // TODO: add Json messages files
    std::string jsonMess = "";
    std::string result = parser.parseRequest(jsonMess);
}