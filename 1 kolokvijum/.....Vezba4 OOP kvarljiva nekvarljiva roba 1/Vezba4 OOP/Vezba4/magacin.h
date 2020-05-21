#ifndef MAGACIN_H_INCLUDED
#define MAGACIN_H_INCLUDED
#include "roba.h"
#include <vector>

class Magacin{
public:
    string ime;
    vector <Roba*> roba;

    Magacin(string ime){
        this->ime = ime;
    }

    string getIme(){
        return this->ime;
    }

    void setIme(string nIme){
        this->ime = nIme;
    }



    void dodavanje(Roba* r){
        roba.push_back(r);
    }


    void ispis(){
        int brojac = 1;
        for(size_t i = 0; i<roba.size(); i++){
            cout<<brojac<<" ";
            roba[i]->detalji();
            brojac++;
        }
    }
};

#endif // MAGACIN_H_INCLUDED
