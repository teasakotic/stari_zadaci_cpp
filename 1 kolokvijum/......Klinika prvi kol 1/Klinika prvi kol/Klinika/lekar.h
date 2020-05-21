#ifndef LEKAR_H_INCLUDED
#define LEKAR_H_INCLUDED
#include "zaposleni.h"

class Lekar:public Zaposleni{
public:
    Lekar(string ime, string prezime, string datumRodjenja, string sifra):Zaposleni(ime, prezime, datumRodjenja, sifra){};

    void predstaviSe(){
        cout<<getIme()<<" | "<<getPrezime()<<" | "<<getSifra()<<" | "<<" Lekar"<<endl;
    }
};

#endif // LEKAR_H_INCLUDED
