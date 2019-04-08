#include <iostream>
#include "../include/Document.h"
#include "../include/DraftState.h"
#include "../include/UserFile.h"
#include "../include/Publisher.h"
#include "../include/Subscriber.h"
#include "../include/CommandHandler.h"

int main() {
    std::cout << "hello, world" << std::endl;

    Document document = UserFile();
    DraftState state1 = DraftState();
    DraftState state2 = DraftState(document);
    document.setState(state2);
    document.saveDocument();
    document.setState(state1);
    document.saveDocument();

    CommandHandler handler = CommandHandler();
    Subscriber subscriber = Subscriber(handler);
    Publisher publisher = Publisher();
    publisher.notifySubscriber(subscriber);
    return 0;
}