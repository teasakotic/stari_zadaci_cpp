#include <iostream>

#include "creature.h"
#include "magic_creature.h"

using namespace std;

int main()
{
    Creature player(10, 2, "Player");
    player.addItem(new Item("useless trinket"));
    MagicCreature hostileMage(20, 1, 3, "Angry Mage");

    cout << player.introduce() << endl;
    cout << hostileMage.introduce() << endl;
    cout << endl;
    cout << "Battle phase!" << endl;
    cout << endl;

    player.attack(hostileMage);
    player.getItem(0)->use();
    if(hostileMage.isAlive()) {
        hostileMage.magicAttack(player);
    }

    cout << "Round 1 results:" << endl;
    cout << "\t" << player.getName() << ":" << endl;
    cout << "\t\tHP: " << player.getHp() << endl;
    cout << endl;
    cout << "\t" << hostileMage.getName() << ":" << endl;
    cout << "\t\tHP: " << hostileMage.getHp() << endl;
    return 0;
}
