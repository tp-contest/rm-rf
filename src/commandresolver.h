#ifndef COMMANDRESOLVER
#define COMMANDRESOLVER

#include "Document.h"
#include "Person.h"
#include <string>
#include <fstream>
#include <vector>

class CommandResolver{
protected:
    Person * pers;
    Document * doc;

public:
    virtual ~CommandResolver;
    virtual void Execute()=0;
    virtual void unExectute()=0;

    void setDocument(Document * _doc){
        doc = _doc;
    }

    void setPerson(Person * _pers){
        pers = _pers;
    }
};

#endif // COMMANDRESOLVER

