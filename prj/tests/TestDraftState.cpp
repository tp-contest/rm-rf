//
// Created by d on 08.04.19.
//

#include "gtest/gtest.h"
#include "../include/UserFile.h"
#include "../include/DraftState.h"

TEST(DraftStateSuit, editDocument) {
    UserFile document = UserFile();
    DraftState state = DraftState(document);
    bool result = state.saveDocument();
    ASSERT_TRUE(result);
}

TEST(DraftStateSuit, deleteDocument) {
    UserFile document = UserFile();
    DraftState state = DraftState(document);
    bool result = state.deleteDocument();
    ASSERT_TRUE(result);
}

TEST(DraftStateSuit, saveDocument) {
    UserFile document = UserFile();
    DraftState state = DraftState(document);
    bool result = state.saveDocument();
    ASSERT_TRUE(result);
}