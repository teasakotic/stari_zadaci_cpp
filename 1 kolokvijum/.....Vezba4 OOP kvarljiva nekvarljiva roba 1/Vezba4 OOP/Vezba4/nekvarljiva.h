#ifndef NEKVARLJIVA_H_INCLUDED
#define NEKVARLJIVA_H_INCLUDED
#include "roba.h"

class Nekvarljiva : public Roba{
public:
    Nekvarljiva(string ime, float cena, float kolicina, string sifra):Roba(ime, cena, kolicina, sifra){
        this->ime = ime;
        this->cena = cena;
        this->kolicina = kolicina;
        this->sifra = sifra;
    }

    void detalji(){
        cout<<getIme()<<" | "<<getCena()<<endl;
    }
};

#endif // NEKVARLJIVA_H_INCLUDED
