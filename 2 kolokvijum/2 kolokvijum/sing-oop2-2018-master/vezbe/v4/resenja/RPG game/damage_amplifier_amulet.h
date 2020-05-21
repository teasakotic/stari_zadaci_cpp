#ifndef DAMAGE_AMPLIFIER_AMULET_H_INCLUDED
#define DAMAGE_AMPLIFIER_AMULET_H_INCLUDED

#include "passive_item.h"

class Creature;

class DamageAmplifierAmulet : public PassiveItem {
    public:
        DamageAmplifierAmulet(string name) : PassiveItem(name) {};
        virtual void use();
        virtual void use(Creature &);
};

#endif // DAMAGE_AMPLIFIER_AMULET_H_INCLUDED
