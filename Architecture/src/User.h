//
// Created by yu on 08.04.19.
//

#ifndef MYPROJECT_USER_H
#define MYPROJECT_USER_H

#include "Person.h"
#include "Contest.h"

class User: public Person{
private:
    list<Contest> participation;
public:
    bool applyForContest(Contest newParticipation);
};


#endif //MYPROJECT_USER_H
