#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <string>

#include "creature.h"

using namespace std;

class Event {
    protected:
        string title;
        string content;
        string parseContent(string content, string key, string value); //Pomocna metoda za pravljenje poruka u dogadjajima.
    public:
        Event(string title, string content) : title(title), content(content) {};
        virtual void execute(Creature &target)=0;
};

#endif // EVENT_H_INCLUDED
