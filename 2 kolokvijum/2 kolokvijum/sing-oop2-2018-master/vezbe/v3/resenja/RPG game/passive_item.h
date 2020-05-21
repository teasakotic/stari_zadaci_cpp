#ifndef PASSIVE_ITEM_H_INCLUDED
#define PASSIVE_ITEM_H_INCLUDED

#include "item.h"

class Creature;

class PassiveItem : public Item {
    public:
        PassiveItem(string name) : Item(name){type = "passive item";};
        virtual void use()=0;
        virtual void use(Creature &target);
};

#endif // PASSIVE_ITEM_H_INCLUDED
