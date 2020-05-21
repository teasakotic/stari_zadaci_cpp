#ifndef RACUNAR_H_INCLUDED
#define RACUNAR_H_INCLUDED
#include "deo.h"
#include <vector>

class Racunar{
public:
    string nazivProoizvodjaca;
    string model;
    vector <Deo*> delovi;

    Racunar(string nazivProoizvodjaca, string model){
        this->nazivProoizvodjaca = nazivProoizvodjaca;
        this->model = model;
    }

    string getNazivProizvodjaca(){
        return this->nazivProoizvodjaca;
    }

    string getModel(){
        return this->model;
    }

    void setNazivProizvodjaca(string nNazivProizvodjaca){
        this->nazivProoizvodjaca = nNazivProizvodjaca;
    }

    void setModel(string nModel){
        this->model = nModel;
    }

    void dodavanjeUvektor(Deo * d){
        delovi.push_back(d);
    }

    virtual bool ispravnost()=0;
    virtual void servis()=0;
};

#endif // RACUNAR_H_INCLUDED
