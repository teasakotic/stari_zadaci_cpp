#ifndef DEO_H_INCLUDED
#define DEO_H_INCLUDED
#include <iostream>
using namespace std;

class Deo{
public:
    //atributi
    string nazivProizvodjaca;
    string nazivDela;
    float ostecenostDela;

    //konstruktor
    Deo(string nazivProizvodjaca, string nazivDela, float ostecenostDela){
        this->nazivProizvodjaca = nazivProizvodjaca;
        this->nazivDela = nazivDela;
        this->ostecenostDela = ostecenostDela;
    }

    //geteri
    string getNazivProizvodjaca(){
        return this->nazivProizvodjaca;
    }

    string getNazivDela(){
        return this->nazivDela;
    }

    float getOstecenostDela(){
        return this->ostecenostDela;
    }

    //seteri
    void setNazivProizvodjaca(string nNazivProizvodjaca){
        this->nazivProizvodjaca = nNazivProizvodjaca;
    }

    void setNazivDela(string nNazivDela){
        this->nazivDela = nNazivDela;
    }

    void setOstecenostDela(float nOstecenostDela){
        this->ostecenostDela = nOstecenostDela;
    }

    virtual void ispis()=0;
    virtual bool ispravnost()=0;
    virtual void upotrebi(float predjeniPut)=0;
};

#endif // DEO_H_INCLUDED
