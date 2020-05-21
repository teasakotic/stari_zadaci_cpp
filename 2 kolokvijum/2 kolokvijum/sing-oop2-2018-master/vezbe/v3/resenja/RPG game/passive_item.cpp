#include "passive_item.h"
#include "creature.h"

void PassiveItem::use() {
    cout << "Passive item " << name << " has no effect!" << endl;
}

void PassiveItem::use(Creature &target) {
    cout << "Passive item " << name << " used on " << target.getName() << endl;
}
