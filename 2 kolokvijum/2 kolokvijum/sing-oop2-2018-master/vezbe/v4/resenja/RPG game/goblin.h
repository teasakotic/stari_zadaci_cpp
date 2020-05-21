#ifndef GOBLIN_H_INCLUDED
#define GOBLIN_H_INCLUDED

#include <iostream>

using namespace std;

class Goblin : public Creature {
    public:
        Goblin(double hp, double baseDamage, string name) : Creature(hp, baseDamage, name) {};
        virtual bool isAlive(){return Creature::isAlive();}
        virtual void attack(Creature &other) {
            cout << "No, no! You're not supposed to be here!" << endl;
            Creature::attack(other);
        }
};

#endif // GOBLIN_H_INCLUDED
