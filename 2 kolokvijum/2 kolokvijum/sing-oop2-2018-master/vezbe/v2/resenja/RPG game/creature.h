#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

#include <string> //Zaglavlje klase string
#include <vector> //Zaglavlje klase vector

#include "item.h" //Zaglavlje koje sadrzi deklaraciju i definiciju klase Item

using namespace std;

class Creature { //Deklaracija i definicija klase creature
    protected:
        double hp;
        double baseDamage;
        string name;
        vector<Item*> inventory; //Vektor pokazivaca na objekte tipa Item.
                                 //ne moze biti referenca jer se ne moze napraviti
                                 //niz referenci. Implementacija vektora koristi
                                 //nizove za skladistenje podataka.

    public:
        Creature(double, double, string); //Nazivi parametara u deklaracijama metoda
                                          //ne moraju biti navedeni.
        double getHp() {return hp;}
        void setHp(double);
        double getBaseDamage() {return baseDamage;}
        void setBaseDamage(double);
        string getName() {return name;}
        void setName(string);
        void addItem(Item* item) {inventory.push_back(item);} //Metoda push_back vrsi dodavanje elemenata na kraj vektora.
        Item* getItem(int index) {return inventory[index];} //Elementima vektora se moze pristupati preko indeksa kao i elementima obicnog niza.
        bool isAlive();
        string introduce();
        void attack(Creature&); //Prosledjuje se referenca jer je neophodno menajti vrednosti prosledjenog objekta.
};


#endif // CREATURE_H_INCLUDED
