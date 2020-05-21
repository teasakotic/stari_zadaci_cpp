#ifndef TORBA_H_INCLUDED
#define TORBA_H_INCLUDED
#include "oblik.h"
#include <vector>

class Torba{
public:
    //atributi
    string ime;
    vector <Oblik*> oblici;

    //konstruktor
    Torba(string ime){
        this->ime = ime;
    }

    //geter
    string getIme(){
        return this->ime;
    }

    void setIme(string nIme){
        this->ime = nIme;
    }

    //metode
    void dodavanje(Oblik* o){
        oblici.push_back(o);
    }

    void ispis(){
        for(size_t i = 0; i<oblici.size(); i++){
            oblici[i]->iscrtaj();
        }
    }

};

#endif // TORBA_H_INCLUDED
