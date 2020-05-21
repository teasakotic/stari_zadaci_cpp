#include "inventory.h"

Inventory::Inventory(int capacity) : capacity(capacity) {
    itemCount = 0; //Inicijalno je inventar prazan.
    inventory = new Item*[capacity]; //Dinamicki se alocira prostor za niz pokazivaca
                                     //na instance klase Item cija duzina je jednaka
                                     //vrednosti atributa capacity.
}

bool Inventory::addItem(Item* item) {
    //Ukoliko ima prostora vrsi se dodavanje
    //novog elementa na prvu praznu poziciju.
    if(itemCount < capacity) {
        inventory[itemCount] = item;
        itemCount += 1; //Nakon uspesnog dodavanja uvecava se
                        //broj elemenata u nizu.
        return true;
    }
    return false;
}

bool Inventory::removeItem(int index) {
    //Metoda za uklanjanje elementa ne oslobadja prostor
    //zauzet za element vec samo umanjuje broj elemenata
    //i elemente nakon uklonjenog elementa pomera za po
    //jedno mesto u levo.
    if(index < 0 || index >= capacity) { //Proverava da li ima smisla vrsiti uklanjanje.
        return false;
    }

    //Ako ima potrebe, ovde bi bilo moguce i osloboditi
    //prostor za uklonjeni element, npr. delete inventory[index];

    for(int i = index; i < itemCount-1; i++) { //Petlja koja pomera sve elemente
                                               //niza za po jedno mesto u levo.
        inventory[i] = inventory[i+1];
    }

    itemCount -= 1; //Umanjuje se broj elemenata u nizu.
    return true;
}

Inventory::~Inventory() {
    //Oslobadja prostor rezervisan za niz pokazivaca.
    //Medjutim ovo ne otklanja pojedinacne Item objekte iz memorije.
    delete [] inventory;

    //Ukoliko je neophodno otkoloniti i Item objekte iz memorije
    //mora se proci kroz citav niz i pojedinacno ukloniti svaka Item
    //instanca pa potom osloboditi prostor za niz.
    /*
    for(int i = 0; i < itemCount; i++) {
        delete inventory[i];
    }

    delete [] inventory;
    */
}
