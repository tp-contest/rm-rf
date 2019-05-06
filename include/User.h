#ifndef MYPROJECT_USER_H
#define MYPROJECT_USER_H

#include <map>
#include "Person.h"
#include "Contest.h"
#include "Status.h"

using std::map;

class User: public Person{
private:
    map<string, Contest> contests_;
public:
    Status applyForContest(const Contest &newContest) { return Ok; };
    Status sendCommit(string ContestID) { return Ok };
};


#endif //MYPROJECT_USER_H
