//
// Created by horosheninad
//

#include <iostream>
#include "src/admin/admin.h"

int main() {
    Admin admin;
    if (admin.createContest("title", "task", 0)) {
        std::cout << "create";
    } else {
        std::cout << "not create";
    }
    return 0;
}