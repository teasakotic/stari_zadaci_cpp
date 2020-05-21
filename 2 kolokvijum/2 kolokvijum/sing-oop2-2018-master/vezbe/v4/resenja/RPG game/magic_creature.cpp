#include "magic_creature.h"

MagicCreature::MagicCreature(double hp, double baseDamage, double mp, string name) : Creature(hp, baseDamage, name), mp(mp) {
                                                                                    //U inicijalizacionoj listi se poziva i
                                                                                    //konstruktor super klase Creature.
                                                                                    //Parametri neophodni za inicijalizaciju
                                                                                    //super klase se prosledjuju konstruktoru
                                                                                    //klase Creature.
}

string MagicCreature::introduce() {
    //Metoda introduce klase MagicCreature poziva metodu introduce
    //iz klase Creature.
    return Creature::introduce() + " Wooosh! You have a small wand!";
}

bool MagicCreature::isAlive() {
    return Creature::isAlive();
}

void MagicCreature::magicAttack(Creature &other) {
    attack(other); //Poziv metode attack iz klase Creature.
                   //Nije bilo neophodno navoditi da je metoda
                   //iz opsega klase Creature jer ne postoji
                   //redefinicija metode attack u klasi MagicCreature.
}
