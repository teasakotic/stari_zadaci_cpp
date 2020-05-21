#ifndef ROBA_H_INCLUDED
#define ROBA_H_INCLUDED
#include <iostream>
using namespace std;

class Roba{
public:
    string ime;
    float cena;
    float kolicina;
    string sifra;

    Roba(string ime, float cena, float kolicina, string sifra){
        this->ime = ime;
        this->cena = cena;
        this->kolicina = kolicina;
        this->sifra = sifra;
    }

    string getIme(){
        return this->ime;
    }

    float getCena(){
        return this->cena;
    }

    float getKolicina(){
        return this->kolicina;
    }

    string getSifra(){
        return this->sifra;
    }

    void setIme(string nIme){
        this->ime = nIme;
    }

    void setCena(float nCena){
        this->cena = nCena;
    }

    void setKolicina(float nKolicina){
        this->kolicina = nKolicina;
    }

    void setSifra(string nSifra){
        this->sifra = nSifra;
    }

    virtual void detalji()=0;

};

#endif // ROBA_H_INCLUDED
