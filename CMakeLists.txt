cmake_minimum_required(VERSION 3.13)
project(prj)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
add_executable(prj src/main.cpp include/Subscriber.h include/ISubscriber.h src/CommandHandler.cpp include/CommandHandler.h include/Parser.h src/JsonParser.cpp include/JsonParser.h src/Publisher.cpp include/Publisher.h include/Handler.h src/Document.cpp include/Document.h src/DraftState.cpp include/DraftState.h src/PublishedState.cpp include/PublishedState.h src/Subscriber.cpp tests/TestSubscriber.cpp include/DocumentState.h include/UserFile.h tests/TestJsonParser.cpp tests/TestCommandHandler.cpp tests/TestDocument.cpp tests/TestUserFile.cpp tests/TestDraftState.cpp tests/TestPublishedState.cpp include/User.h include/NoUserHandler.h src/UserHandler.cpp include/UserHandler.h src/AdminHandler.cpp include/AdminHandler.h)
add_test(prj src/main.cpp src/Subscriber.cpp include/Subscriber.h src/main_test.cpp)

target_link_libraries(prj gtest gtest_main)