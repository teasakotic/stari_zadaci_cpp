#ifndef AUTOMOBIL_H_INCLUDED
#define AUTOMOBIL_H_INCLUDED
#include "deo.h"
#include <vector>

class Automobil{
public:
    //atributi
    string nazivProizvodjaca;
    string model;
    vector <Deo*> delovi;

    //konstruktor
    Automobil(string nazivProizvodjaca, string model){
        this->nazivProizvodjaca = nazivProizvodjaca;
        this->model = model;
    }

    //geteri
    string getNazivProizvodjaca(){
        return this->nazivProizvodjaca;
    }

    string getModel(){
        return this->model;
    }

    //seteri
    void setNazivProizvodjaca(string nNazivProizvodjaca){
        this->nazivProizvodjaca = nNazivProizvodjaca;
    }

    void setModel(string nModel){
        this->model = nModel;
    }

    void dodavanje(Deo* d){
        delovi.push_back(d);
    }

    //metode
    virtual bool ispravnost()=0;
    virtual void vozi(float duzinaVoznje)=0;
    virtual void tehnickiPregled()=0;
};

#endif // AUTOMOBIL_H_INCLUDED
