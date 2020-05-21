#ifndef AUDI_H_INCLUDED
#define AUDI_H_INCLUDED
#include "automobil.h"

class Audi : public Automobil{
public:
    Audi(string nazivProdzvodjaca, string model):Automobil(nazivProizvodjaca, model){
        this->nazivProizvodjaca = nazivProizvodjaca;
        this->model = model;
    }

    bool ispravnost(){
        for(size_t i = 0; i<delovi.size(); i++){
            if(delovi[i]->ispravnost()==true){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }

    void vozi(float duzinaVoznje){
        for(size_t i = 0; i<delovi.size(); i++){
            delovi[i]->upotrebi(duzinaVoznje);
        }
        cout<<"Automobil: "<<getNazivProizvodjaca()<<", "<<getModel()<<" je zavrsio voznju duzine "<<duzinaVoznje<<endl;
    }

    void tehnickiPregled(){
        for(size_t i = 0; i<delovi.size(); i++){
            delovi[i]->ispis();
        }
    }
};

#endif // AUDI_H_INCLUDED
