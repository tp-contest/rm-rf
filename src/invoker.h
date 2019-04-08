#ifndef INVOKER
#define INVOKER

#include <string>
#include <fstream>
#include <vector>
#include "Document.h"
#include "commandresolver.h"

class Invoker{
       vector<Command*> DoneCommands;
       Document doc;
       CommandResolver* command;
public:
       void Insert(string * _fin, const string _name){
           command = new InsertCommand(_fin, _name);
           command->setDocument(&doc);
           command->Execute();
           DoneCommands.push_back(command);
       }



}


#endif // INVOKER

