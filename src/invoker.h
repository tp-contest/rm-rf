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
       void Insert(ofstream * _fin, const string _name){
           return 1;
       }
}


#endif // INVOKER