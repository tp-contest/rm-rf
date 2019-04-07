//
// Created by yu on 08.04.19.
//

#ifndef MYPROJECT_COMMIT_H
#define MYPROJECT_COMMIT_H

#include <iostream>
#include <string>

using std::string;

class Commit {

private:
    int ID;
    time_t sendTime;
    string result;
public:
    Commit();

    ~Commit();

};


#endif //MYPROJECT_COMMIT_H
