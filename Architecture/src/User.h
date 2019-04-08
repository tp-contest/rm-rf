#ifndef MYPROJECT_USER_H
#define MYPROJECT_USER_H

#include <map>
#include "Person.h"
#include "Contest.h"

using std::map;

class User: public Person{
private:
    map<string, Contest> contests_;
public:
    status applyForContest(const Contest &newContest){};
    status sendCommit(string ContestID){};
};


#endif //MYPROJECT_USER_H
