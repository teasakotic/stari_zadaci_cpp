#include "damage_amplifier_amulet.h"
#include "creature.h"

void DamageAmplifierAmulet::use() {
    cout << "Item " << name << " used!" << endl;
}

void DamageAmplifierAmulet::use(Creature &target) {
    cout << "Can not use " << name << " on " << target.getName() << "!" << endl;
}
