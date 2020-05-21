#ifndef OSOBA_H_INCLUDED
#define OSOBA_H_INCLUDED
#include <iostream>
using namespace std;

class Osoba{
public:
    string ime;
    string prezime;
    string datumRodjenja;

    Osoba(string ime, string prezime, string datumRodjenja){
        this->ime = ime;
        this->prezime = prezime;
        this->datumRodjenja = datumRodjenja;
    }

    string getIme(){
        return this->ime;
    }

    string getPrezime(){
        return this->prezime;
    }

    string getDatumRodjenja(){
        return this->datumRodjenja;
    }

    void setIme(string nIme){
        this->ime = nIme;
    }

    void setPrezime(string nPrezime){
        this->prezime = nPrezime;
    }

    void setDatumRodjenja(string nDatumRodjenja){
        this->datumRodjenja = nDatumRodjenja;
    }

    virtual void predstaviSe()=0;
};

#endif // OSOBA_H_INCLUDED
