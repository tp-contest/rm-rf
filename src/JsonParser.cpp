//
// Created by d on 07.04.19.
//

#include "../include/JsonParser.h"

int JsonParser::JsonContest(const Contestjson &contest)  {
    {
        try {
            Contestjson contestin(contest);
            pt::ptree contestout;

            contestout.put("task_id", contestin.tasks_list_id);
            contestout.put("script_id", contestin.script_id);
            contestout.put("contest_id", contestin.contest_id);

            pt::write_json(boost::asio::streambuf, contestout);
        }
        catch(const boost::property_tree::ptree_error& e) {
            std::cerr << "Boost property tree error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
        catch (...) {
            std::cerr << "Unknown error occurred" << std::endl;
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }
}

int JsonParser::JsonHuman(const Humanjson &manin) {
    try {

        Humanjson man(manin);
        pt::ptree human;

        human.put("name", man.name);
        human.put("surname", man.surname);
        human.put("password", man.password);
        human.put("username", man.username);
        human.put("group_id", man.group_id);

        pt::write_json(boost::asio::streambuf, human);
    }
    catch(const boost::property_tree::ptree_error& e) {
        std::cerr << "Boost property tree error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "Unkown error occurred" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}

int JsonParser::JsonMyContest(const MyContestjson &contest) {
    {
        try {

            MyContestjson contestin(contest);
            pt::ptree contestout;

            contestout.put("file", contestin.file);
            contestout.put("file_id", contestin.file_id);
            contestout.put("script_id", contestin.user_id);
            contestout.put("task_id", contestin.task_id);
            contestout.put("package_id", contestin.package_id);
            contestout.put("solution_id", contestin.solution_id);

            pt::write_json(boost::asio::streambuf, contestout);
        }
        catch(const boost::property_tree::ptree_error& e) {
            std::cerr << "Boost property tree error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
        catch (...) {
            std::cerr << "Unknown error occurred" << std::endl;
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }

}

int JsonParser::JsonTask(const Taskjson &task) {
    {

        try {

            Taskjson taskin(task);
            //read let's register taskout
            pt::ptree taskout;

            taskout.put("task_id", taskin.task_id);
            taskout.put("file", taskin.file);
            taskout.put("description", taskin.description);
            taskout.put("script_id", taskin.script_id);
            taskout.put("contest_id", taskin.contest_id);

            pt::write_json(boost::asio::streambuf, taskout);
        }
        catch(const boost::property_tree::ptree_error& e) {
            std::cerr << "Boost property tree error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
        catch (...) {
            std::cerr << "Unkown error occurred" << std::endl;
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;

    }
}



