#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include "item.h"

class Inventory {
    protected:
        int capacity; //Maksimalni kapacitet inventara.
        int itemCount; //Ukupan broj zauzetih mesta u inventaru.
        Item** inventory; //Pokazivac na pokazivac na instancu tipa Item.
                          //Bice upotrebljen za kreiranje niza pokazivaca na Item instance.
    public:
        Inventory(int capacity=5); //Podrazumevana vrednost argumenta
                                   //moze biti navedena pri deklaraciji
                                   //metode ili konstruktora.
        virtual int size() {return itemCount;}; //Vraca broj elemenata u kolekciji.
        virtual Item* getItem(int index) {return inventory[index];};
        virtual bool addItem(Item*);
        virtual bool removeItem(int index);
        virtual ~Inventory(); //Destruktor instanci klase Inventory.
                              //Kljucna rec virtual je neophodna kako bi
                              //se ispravno pozvao lanac destruktora.
                              //Ukoliko se izostavi nece biti obezbedjeno
                              //pozivanje destruktora od klase naslednice pa
                              //sve do korenske roditeljske klase.
};

#endif // INVENTORY_H_INCLUDED
