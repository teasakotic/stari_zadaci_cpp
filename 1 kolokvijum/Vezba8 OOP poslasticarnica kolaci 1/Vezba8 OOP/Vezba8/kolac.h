#ifndef KOLAC_H_INCLUDED
#define KOLAC_H_INCLUDED
#include <iostream>
using namespace std;

class Kolac{
public:
    string naziv;
    float cena;
    float kolicina;

    Kolac(string naziv, float cena, float kolicina){
        this->naziv = naziv;
        this->cena = cena;
        this->kolicina = kolicina;
    }

    string getNaziv(){
        return this->naziv;
    }

    float getCena(){
        return this->cena;
    }

    float getKolicina(){
        return this->kolicina;
    }

    void setNaziv(string nNaziv){
        this->naziv = nNaziv;
    }

    void setCena(float nCena){
        this->cena = nCena;
    }

    void setKolicina(float nKolicina){
        this->kolicina = nKolicina;
    }

    virtual void prikaz()=0;
    virtual float umanji(float k)=0;
};

#endif // KOLAC_H_INCLUDED
