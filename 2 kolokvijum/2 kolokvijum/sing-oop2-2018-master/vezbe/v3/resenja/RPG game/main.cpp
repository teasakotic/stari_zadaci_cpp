#include <iostream>

#include "creature.h"
#include "goblin.h"
#include "magic_creature.h"
#include "troll.h"

#include "item.h"
#include "passive_item.h"
#include "damage_amplifier_amulet.h"

#include "event.h"
#include "encounter.h"
#include "tumble_event.h"
#include "ambush.h"

using namespace std;

int main()
{
    Creature *player = new MagicCreature(10, 2, 5, "Player"); //Posto se dinamicki obezbedjuje prostor i kreira objekat
                                                              //koristi se kljucna rec new. Rezultat izraza sa desne
                                                              //strane znaka jednakosti je pokazivac na alocirani prostor
                                                              //za novu instancu.
    //Popunjavanje inventara.
    player->addItem(new DamageAmplifierAmulet("Red stone of Aja"));
    player->addItem(new DamageAmplifierAmulet("Necklace of inconvenience"));
    player->addItem(new DamageAmplifierAmulet("Amulet of incompetence"));

    //Dinamicko rezervisanje memorije i kreiranje protivnika.
    Creature *hostileMage = new MagicCreature(20, 1, 3, "Angry Mage");
    Creature *goblin = new Goblin(5, 1, "Snarl Burbleskew");
    Troll *troll = new Troll(50, 5, 10, "Archibald the troll");

    //Kreiranje dogadjaja
    Event *firstTumble = new TumbleEvent();
    Encounter *firstAmbush = new Ambush();
    Encounter *secondAmbush = new Ambush();

    //Popunjavanje Encounter dogadjaja ucesnicima.
    firstAmbush->addActor(hostileMage);
    firstAmbush->addActor(goblin);

    secondAmbush->addActor(troll);

    //Kreiranje vektora dogadjaja
    vector<Event*> events;
    events.push_back(firstTumble);
    events.push_back(firstAmbush);
    events.push_back(new TumbleEvent());
    events.push_back(new TumbleEvent());
    events.push_back(secondAmbush);
    events.push_back(new TumbleEvent());

    /*
    //Prethodni nacin realizacije igre.
    cout << player->introduce() << endl;
    cout << hostileMage->introduce() << endl;
    cout << endl;
    cout << "Battle phase!" << endl;
    cout << endl;

    player->attack(*hostileMage);
    cout << endl;
    if(hostileMage->isAlive()) {
        hostileMage->attack(*player);
    }
    cout << endl;
    goblin->attack(*player);
    cout << endl;
    troll->attack(*player);
    cout << endl;

    cout << "Round 1 results:" << endl;
    cout << "\t" << player->getName() << ":" << endl;
    cout << "\t\tHP: " << player->getHp() << endl;
    cout << endl;
    cout << "\t" << hostileMage->getName() << ":" << endl;
    cout << "\t\tHP: " << hostileMage->getHp() << endl;
    */

    //Realizacija igre preko dogadjaja.
    for(size_t i = 0; i < events.size(); i++) {
        cout << "---------" << endl;
        events[i]->execute(*player); //Posto metoda execute prima referencu, prvo
                                     //je neophodno dereferencirati pokazivac
                                     //kako bi se dobio objekat na koji bi se mogla
                                     //dobiti referenca.
                                     //Operator zvezdica vrsi dereferenciranje.
                                     //Takodje posto su u vektoru dogadjaja smesteni
                                     //pokazivaci na instance klase Event prvo je
                                     //neophodno dereferencirati pokazivace pa onda
                                     //pristupiti metodi. Za to se koristi operator ->
                                     //koji predstavlja skraceni zapis za (*pokazivac).metoda()
                                     //odnosno dereferenciranje pa pozive metode nad objektom.
    }
    return 0;
}
