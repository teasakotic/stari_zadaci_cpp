#ifndef KLINIKA1_H_INCLUDED
#define KLINIKA1_H_INCLUDED
#include "osoba.h"
#include <vector>

class Klinika1{
public:
    string imeKlinike;
    vector <Osoba*> osobe;

    Klinika1(string imeKlinike){
        this->imeKlinike = imeKlinike;
    }

    string getImeKlinike(){
        return this->imeKlinike;
    }

    void setImeKlinke(string nImeKlinike){
        this->imeKlinike = nImeKlinike;
    }

    void dodavanjeUVektor(Osoba* o){
    osobe.push_back(o);
    }

    void ispis(){
        int k = 1;
        for(size_t i=0; i<osobe.size(); i++){
        cout<<k<<" | ";
        osobe[i]->predstaviSe();
        k++;
    }
    }
};

#endif // KLINIKA1_H_INCLUDED
