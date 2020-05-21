#include "creature.h"

Creature::Creature(double hp, double baseDamage, string name) : hp(hp), baseDamage(baseDamage), name(name) {
                                                                //Atributi navedeni u inicijalizacionoj listi
                                                                //se inicijalizuju pre poziva tela konstruktora.
                                                                //Atribute koji predstavljaju reference neophodno je
                                                                //inicijalizovati pre poziva tela konstruktora kako
                                                                //ne bi dobili podrazumevane vrednosti koje se dodeljuju
                                                                //u trenutku inicijalizacije objekta.
                                                                //Zapis inicijalizacione liste: : ime_atributa(vrednosto), ...
}

void Creature::setHp(double hp) {
    this->hp = hp;
}

void Creature::setBaseDamage(double bd) {
    this->baseDamage = bd;
}

void Creature::setName(string name) {
    this->name = name;
}

bool Creature::isAlive() { //Izvedeni atribut, racuna se na osnovu vrednosti hp.
    return hp > 0;
}

string Creature::introduce() {
    return "I am " + name + "!";
}

void Creature::attack(Creature &other) {
    //Metoda attack realizovana je tako da prosledjenoj instanci
    //klase Creature umanji vrednosta atributa hp za vrednost svog
    //atributa baseDamage.
    //Pre izvodjenja napada poziva se metoda use nad svim instancama
    //PassiveItem klase u inventory vektoru.
    cout << name << " attacks!" << endl;
    for(size_t i = 0; i < inventory.size(); i++) {
        if(inventory[i]->getType() == "passive item") {
            inventory[i]->use();
        }
    }
    other.setHp(other.getHp() - baseDamage);
}
