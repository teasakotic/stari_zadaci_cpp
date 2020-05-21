#ifndef TORTA_H_INCLUDED
#define TORTA_H_INCLUDED
#include <iostream>
using namespace std;

class Torta{
public:
    //atributi
    string ime;
    float kolicina;

    //konstruktor
    Torta(string ime, float kolicina){
        this->ime = ime;
        this->kolicina = kolicina;
    }

    //geteti
    string getIme(){
        return this->ime;
    }

    float getKolicina(){
        return this->kolicina;
    }

    //seteri
    void setIme(string nIme){
        this->ime = nIme;
    }

    void setKolicina(float nKolicina){
        this->kolicina = nKolicina;
    }

    //metode
    virtual void ispis()=0;
};

#endif // TORTA_H_INCLUDED
