#include <iostream>
#include "src/Person.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Person person;
    if (person.authorization("Goshan", "228228")) {
        std::cout << "Log in";
    } else {
        std::cout << "Log out";
    }
    return 0;
}