cmake_minimum_required(VERSION 3.13)
project(prj)

find_package(Boost COMPONENTS system filesystem REQUIRED)
find_library(CPPREST_LIB cpprest)
find_package(OpenSSL REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

link_libraries(crypto )
#link_libraries(stdc++fs )

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

add_executable(prj
#        include/Admin.h
#        include/CommandHandler.h
        include/Commit.h
        include/Contest.h
        include/Document.h
#        include/DocumentState.h
#        include/DraftState.h
#        include/Handler.h
#        include/ISubscriber.h
#        include/JsonParser.h
#        include/Parser.h
#        include/Person.h
#        include/PublishedState.h
#        include/Publisher.h
#        include/Status.h
#        include/Subscriber.h
#        include/User.h
#        include/UserFile.h
#        src/Admin.cpp
#        src/CommandHandler.cpp
        src/Commit.cpp
        src/Contest.cpp
        src/Document.cpp
#        src/DraftState.cpp
#        src/JsonParser.cpp
#        src/Person.cpp
#        src/PublishedState.cpp
#        src/Publisher.cpp
#        src/Subscriber.cpp
#        tests/TestAdmin.cpp
#        tests/TestCommandHandler.cpp
        tests/TestDocument.cpp
#        tests/TestDraftState.cpp
#        tests/TestJsonParser.cpp
#        tests/TestPublishedState.cpp
#        tests/TestSubscriber.cpp
#        tests/TestUserFile.cpp
        tests/TestCommit.cpp
        tests/TestContest.cpp
        )
add_test(prj src/Subscriber.cpp include/Subscriber.h src/Admin.cpp include/Admin.h src/Commit.cpp include/Commit.h
        src/Contest.cpp include/Contest.h src/main_test.cpp)

target_link_libraries(prj gtest gtest_main ${CPPREST_LIB} ${Boost_LIBRARIES} -lstdc++fs)
