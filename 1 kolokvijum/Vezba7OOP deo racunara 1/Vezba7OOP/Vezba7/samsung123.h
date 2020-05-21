#ifndef SAMSUNG123_H_INCLUDED
#define SAMSUNG123_H_INCLUDED
#include "racunar.h"

class Samsunc123 : public Racunar{
public:
    Samsunc123(string nazivProoizvodjaca, string model):Racunar(nazivProoizvodjaca, model){
        this->nazivProoizvodjaca = nazivProoizvodjaca;
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

    void servis(){
        for(size_t i = 0; i<delovi.size(); i++){
            delovi[i]->ispis();
        }
    }


};

#endif // SAMSUNG123_H_INCLUDED
