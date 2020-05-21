#ifndef AMBUSH_H_INCLUDED
#define AMBUSH_H_INCLUDED

#include <sstream>

#include "encounter.h"

using namespace std;

class Ambush : public Encounter {
    public:
        Ambush() : Encounter("An ambush!", "{TARGET} is ambushed by foul creatures! There is {AMOUNT} of them!") {};
        virtual void execute(Creature &target);
};

#endif // AMBUSH_H_INCLUDED
