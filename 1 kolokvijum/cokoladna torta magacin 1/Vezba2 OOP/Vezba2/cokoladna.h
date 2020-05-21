#ifndef COKOLADNA_H_INCLUDED
#define COKOLADNA_H_INCLUDED
#include "torta.h"

class Cokoladna : public Torta{
public:
    //konstruktor
    Cokoladna(string ime, float kolicina):Torta(ime, kolicina){
        this->ime = ime;
        this->kolicina = kolicina;
    }

    //metode
    void ispis(){
        cout<<"Ime torte je: "<<getIme()<<" i kolicina je "<<getKolicina()<<"g"<<endl;
    }
};

#endif // COKOLADNA_H_INCLUDED
