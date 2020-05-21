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
        virtual double getHp() {return hp;}
        virtual void setHp(double);
        virtual double getBaseDamage() {return baseDamage;}
        virtual void setBaseDamage(double);
        virtual string getName() {return name;}
        virtual void setName(string);
        virtual void addItem(Item* item) {inventory.push_back(item);} //Metoda push_back vrsi dodavanje elemenata na kraj vektora.
        virtual Item* getItem(int index) {return inventory[index];} //Elementima vektora se moze pristupati preko indeksa kao i elementima obicnog niza.
        virtual void removeItem(int index) {inventory.erase(inventory.begin()+index);}; //Uklanjja element vektora na datom indeksu. Metoda erase koristi
                                                                                       //iteratore. Metoda begin vraca iterator na prvi element.
        virtual size_t getItemCount() {return inventory.size();};
        virtual bool isAlive()=0; //Apstraktna klasa se definise kao klasa koja sadrzi barem jednu cistu, pure, virtualnu metodu.
                                  //Ciste virtualne metode ne moraju biti implementirane u klasi u kojoj su deklarisane, niti u naslednicama.
                                  //Ukoliko se cista virtualna metoda ne implementirama u klasi naslednici i ta klasa postaje apstraktna.
        virtual string introduce();
        virtual void attack(Creature&); //Prosledjuje se referenca jer je neophodno menajti vrednosti prosledjenog objekta.
};


#endif // CREATURE_H_INCLUDED
