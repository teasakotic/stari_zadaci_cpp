#ifndef BANKA_H_INCLUDED
#define BANKA_H_INCLUDED
#include "racun.h"
#include <vector>

class Banka{
public:
    string ime;
    vector <Racun*> racuni;

    Banka(string ime){
        this->ime = ime;
    }

    string getIme(){
        return this->ime;
    }

    void setIme(string nIme){
        this->ime = nIme;
    }

    void dodavanjeUvektor(Racun * r){
        racuni.push_back(r);
    }

    virtual void ispisSvihRacuna()=0;
};


#endif // BANKA_H_INCLUDED
