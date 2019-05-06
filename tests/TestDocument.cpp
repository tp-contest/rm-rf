//
// Created by d on 08.04.19.
//

#include "gtest/gtest.h"
#include "../include/Document.h"
#include "../include/DocumentState.h"
#include <stdexcept>
#include <ctime>

TEST(DocumentSuit, setIntId) {
    Document doc;
    doc.setId(0);
    ASSERT_EQ (doc.getId(), 0);
}

TEST(DocumentSuit, setNegId) {
    ASSERT_THROW (Document().setId(-1), std::exception);
}


TEST(DocumentSuit, getId) {
    ASSERT_NE (Document().getId(), 0);
}

/*TEST(DocumentSuit, saveEmptyDocument) {
    ASSERT_THROW(Document().saveDocument(), std::exception);
}*/

TEST(DocumentSuit, deleteEmptyDocument) {
    ASSERT_NO_THROW(Document().deleteDocument());
}

TEST(DocumentSuit, editEmptyDocument) {
    ASSERT_NO_THROW (Document().editDocument());
}
