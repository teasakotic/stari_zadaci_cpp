#include "item.h"
#include "creature.h"

void Item::use() {
    cout << "Item " << name << " has no effect!" << endl;
}

void Item::use(Creature &target) {
    cout << "Item " << name << " used on " << target.getName() << endl;
}
