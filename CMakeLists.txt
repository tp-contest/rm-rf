cmake_minimum_required(VERSION 3.13)
project(prj)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
add_executable(prj
        include/Admin.h
        include/CommandHandler.h
        include/Commit.h
        include/Contest.h
        include/Document.h
        include/DocumentState.h
        include/DraftState.h
        include/Handler.h
        include/ISubscriber.h
        include/JsonParser.h
        include/Parser.h
        include/Person.h
        include/PublishedState.h
        include/Publisher.h
        include/Status.h
        include/Subscriber.h
        include/User.h
        include/UserFile.h
        src/CommandHandler.cpp
        src/Document.cpp
        src/DraftState.cpp
        src/JsonParser.cpp
        src/PublishedState.cpp
        src/Publisher.cpp
        src/Subscriber.cpp
        tests/TestAdmin.cpp
        tests/TestCommandHandler.cpp
        tests/TestDocument.cpp
        tests/TestDraftState.cpp
        tests/TestJsonParser.cpp
        tests/TestPublishedState.cpp
        tests/TestSubscriber.cpp
        tests/TestUserFile.cpp
        )
add_test(prj src/Subscriber.cpp include/Subscriber.h src/ src/main_test.cpp)

target_link_libraries(prj gtest gtest_main)