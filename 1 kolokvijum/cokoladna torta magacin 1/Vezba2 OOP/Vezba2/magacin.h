#ifndef MAGACIN_H_INCLUDED
#define MAGACIN_H_INCLUDED
#include "torta.h"
#include <vector>

class Magacin{
public:
    //atributi
    string ime;
    vector <Torta*> torte;

    //konstruktor
    Magacin(string ime){
        this->ime = ime;
    }

    //metode
    void dodavanje(Torta* t){
        torte.push_back(t);
    }

    void ispis(){
        for(size_t i = 0; i<torte.size(); i++){
            torte[i]->ispis();
        }
    }
};

#endif // MAGACIN_H_INCLUDED
