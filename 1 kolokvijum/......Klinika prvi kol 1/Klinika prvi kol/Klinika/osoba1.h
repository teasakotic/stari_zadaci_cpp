#ifndef OSOBA1_H_INCLUDED
#define OSOBA1_H_INCLUDED
#include "osoba.h"

class Osoba1:public Osoba{
public:
    Osoba1(string ime, string prezime, string datumRodjenja):Osoba(ime, prezime, datumRodjenja){};

    void predstaviSe(){
        cout<<getIme()<<" | "<<getPrezime()<<" | "<<getDatumRodjenja()<<endl;
    }
};

#endif // OSOBA1_H_INCLUDED
