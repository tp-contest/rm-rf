#ifndef MYPROJECT_USER_H
#define MYPROJECT_USER_H

#include <map>
#include "Person.h"
#include "Contest.h"
#include "Status.h"

using std::map;

class User : public Person {
private:
    map<string, Contest> contests;
public:
    Status applyForContest(Contest &newContest);

    Status sendCommit(string &ContestID, Commit &commit);

    void addContest(Contest &contest);

    void deleteContest(const string &contestID);
};

#endif //MYPROJECT_USER_H
