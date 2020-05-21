#ifndef ZAPOSLENI_H_INCLUDED
#define ZAPOSLENI_H_INCLUDED
#include "osoba.h"

class Zaposleni:public Osoba{
public:
    string sifra;

    Zaposleni(string ime, string prezime, string datumRodjenja, string sifra):Osoba(ime, prezime, datumRodjenja){
        this->sifra = sifra;
    }

    string getSifra(){
        return this->sifra;
    }

    void setSifra(string nSifra){
        this->sifra = nSifra;
    }

    virtual void predstaviSe()=0;
};

#endif // ZAPOSLENI_H_INCLUDED
