#ifndef MEDICINSKITEHNICAR_H_INCLUDED
#define MEDICINSKITEHNICAR_H_INCLUDED
#include "zaposleni.h"

class MedicinskiTehnicar:public Zaposleni{
public:
    MedicinskiTehnicar(string ime, string prezime, string datumRodjenja, string sifra):Zaposleni(ime, prezime, datumRodjenja, sifra){};

    void predstaviSe(){
        cout<<getIme()<<" | "<<getPrezime()<<" | "<<getSifra()<<" | "<<" Medicinski tehnicar"<<endl;
    }
};

#endif // MEDICINSKITEHNICAR_H_INCLUDED
