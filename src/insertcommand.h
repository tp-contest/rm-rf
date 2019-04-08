#ifndef INSERTCOMMAND
#define INSERTCOMMAND

#include "commandresolver.h"

class InsertCommand: public CommandResolver{
    ofstream fin;
    string name;
public:
    InsertCommand(ofstream * _fin, const string _name): fin(_fin), srt(_str){}

    void Execute(){
        doc->Insert(fin, name);
    }
};

#endif // INSERTCOMMAND
