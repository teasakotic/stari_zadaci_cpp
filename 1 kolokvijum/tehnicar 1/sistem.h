#ifndef SISTEM_H_INCLUDED
#define SISTEM_H_INCLUDED

#include <iostream>
using namespace std;
#include <vector>
#include "kvar.h"
#include "tehnicar.h"

class Sistem {
private:
    vector<Kvar*> kvarovi;
    vector<Tehnicar*> tehnicari;
public:

    Sistem() {}

    void dodajKvar(Kvar* k){
        kvarovi.push_back(k);

        for (int i = 0; i < tehnicari.size(); i++){


            if (tehnicari[i]->getStruka().compare("mehanicar") && k->getNaslov() == "mehanicki"){
                tehnicari[i]->popravi(k);
            } else if (tehnicari[i]->getStruka() == "elektricar" && k->getNaslov() == "elektricni") {
                tehnicari[i]->popravi(k);
            }
        }
    }

    void dodajTehnicara(Tehnicar* t){
        tehnicari.push_back(t);
    }

    void ispisiSistem(){
        for(int i = 0; i < tehnicari.size(); i++){
            tehnicari[i]->ispisiTehnicara();
        }

        for (int i = 0; i < kvarovi.size(); i++){
            kvarovi[i]->ispisiKvar();
        }
    }
};


#endif // SISTEM_H_INCLUDED
