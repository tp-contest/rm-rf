#include <iostream>
#include <gtest/gtest.h>
#include "../include/Commit.h"
#include "assert.h"
#include <string>

TEST(CommitTest, getCommitId) {
    auto *c = new Commit();
    c->setId("122333");
    string str = c->getCommitId();
    EXPECT_EQ(str, "122333");
    delete c;
}


TEST(CommitTest, Add) {
    auto *c = new Commit();
    std::vector<const char *> paths;
    paths.push_back("/home/yu/Рабочий стол/rm-rf/main.cpp");
    //paths.push_back("not_existing.cpp");

    Status status = c->Add(paths);
    EXPECT_EQ(status, Ok);
    delete c;
}


TEST(CommitTest, getGithub) {
    auto *c = new Commit();

    /*auto fileStream = std::make_shared<concurrency::streams::ostream>();

    pplx::task<void> requestTask = concurrency::streams::fstream::open_ostream(U("results.html")).then([=](concurrency::streams::ostream outFile) {
        *fileStream = outFile;
        web::http::client::http_client client(U("http://www.bing.com/"));
        web::uri_builder builder(U("/search"));
        builder.append_query(U("q"), U("cpprestsdk github"));
        //return client.request(web::http::methods::GET, builder.to_string());
    });*/

    //Status status = c->loadFile("/home/yu/Рабочий стол/rm-rf/main.cpp");
    //EXPECT_EQ(status, Ok);
    delete c;
}