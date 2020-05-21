#ifndef ENCOUNTER_H_INCLUDED
#define ENCOUNTER_H_INCLUDED

#include <vector>

#include "event.h"

using namespace std;

class Encounter : public Event {
    protected:
        vector<Creature*> actors; //Vektor pokazivaca na objekte klase Creature.
    public:
        Encounter(string title, string content) : Event(title, content) {};
        virtual void execute(Creature &target)=0;
        virtual void addActor(Creature *actor) {actors.push_back(actor);};
        virtual Creature* getActor(int index) {return actors[index];};
        virtual void removeActor(int index) {actors.erase(actors.begin()+index);};
};

#endif // ENCOUNTER_H_INCLUDED
