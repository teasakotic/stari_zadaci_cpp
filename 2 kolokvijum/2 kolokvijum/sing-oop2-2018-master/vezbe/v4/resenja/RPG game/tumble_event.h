#ifndef TUMBLE_EVENT_H_INCLUDED
#define TUMBLE_EVENT_H_INCLUDED

#include <iostream>
#include <random>
#include <ctime>
#include <sstream>

#include "event.h"

using namespace std;

class TumbleEvent : public Event {
    public:
        TumbleEvent() : Event("A terrible mishap", "Due to exhaustion {TARGET} tumbles and drops {ITEM}. The {ITEM} is broken and lost forever.") {};
        virtual void execute(Creature &target);
};

#endif // TUMBLE_EVENT_H_INCLUDED
