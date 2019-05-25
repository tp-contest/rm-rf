//
// Created by Alex on 21.05.2019.
//

#ifndef PRJ_JSONMODELS_H
#define PRJ_JSONMODELS_H

#include <string>

struct Contestjson{
    unsigned int contest_id;
    unsigned int script_id;
    unsigned int tasks_list_id;

    Contestjson(const Contestjson &contest):contest_id(contest.contest_id), script_id(contest.script_id),
                                 tasks_list_id(contest.tasks_list_id){

    }

};

struct Humanjson{
    std::string name;
    std::string surname;
    std::string password;
    unsigned int username;
    unsigned int group_id;

    Humanjson(const Humanjson &man):name(man.name), surname(man.surname),
                            password(man.password), username(man.username),
                            group_id(man.group_id){

    }

};

struct MyContestjson{
    std::string file;
    unsigned int file_id;
    unsigned int user_id;
    unsigned int task_id;
    unsigned int package_id;
    unsigned int solution_id;

    MyContestjson(const MyContestjson &myContest):file(myContest.file),file_id(myContest.file_id), user_id(myContest.user_id),
                                          task_id(myContest.task_id), package_id(myContest.task_id), solution_id(myContest.solution_id){

    }

};


struct Taskjson{
    unsigned int task_id;
    std::string file;
    std::string description;
    unsigned int script_id;
    unsigned int contest_id;

    Taskjson(const Taskjson &task):task_id(task.task_id), file(task.file),
                           description(task.description), script_id(task.script_id),
                           contest_id(task.contest_id){

    }

};



#endif //PRJ_JSONMODELS_H
