#ifndef VOCNA_H_INCLUDED
#define VOCNA_H_INCLUDED
#include "torta.h"

class Vocna : public Torta{
public:
    //konstruktor
    Vocna(string ime, float kolicina):Torta(ime, kolicina){
        this->ime = ime;
        this->kolicina = kolicina;
    }

    //metode
    void ispis(){
        cout<<"Ime torte je: "<<getIme()<<" i kolicina je "<<getKolicina()<<"g"<<endl;
    }
};

#endif // VOCNA_H_INCLUDED
