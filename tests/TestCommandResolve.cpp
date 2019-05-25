#include <iostream>
#include <gtest/gtest.h>
#include "../src/commandresolver.h"
#include "assert.h"
#include "../Document.h"

TEST(commandresolverTest, SetDocumetsTest){
    commandresolver cr = commandresolver();
    cr.setDocumet(&doc);
    EXPECT_EQ(cr.doc, doc);
}

TEST(commandresolverTest, SetPersonTest){
    commandresolver cr = CommandResolver();
    cr.setPerson(&person);
    EXPECT_EQ(cr.pers, person);
}
