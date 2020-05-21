#ifndef TROLL_H_INCLUDED
#define TROLL_H_INCLUDED

#include "magic_creature.h"

class Troll : public MagicCreature {
    public:
        Troll(double hp, double baseDamage, double mp, string name) : MagicCreature(hp, baseDamage, mp, name){};
        virtual bool isAlive() {return Creature::isAlive();};
        virtual void attack(Creature &other) {
            cout << "Troll toll!" << endl;
            MagicCreature::attack(other);
        }
};

#endif // TROLL_H_INCLUDED
