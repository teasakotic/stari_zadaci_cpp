#ifndef STAMBENIOBJEKAT_H_INCLUDED
#define STAMBENIOBJEKAT_H_INCLUDED

#include <iostream>
#include <vector>
#include "prostorija.h"
using namespace std;

class StambeniObjekat{
protected:
    string mesto;
    string ulica;
    int broj;
    int godinaProizvodnje;

    vector<Prostorija*> prostorije;

public:

        StambeniObjekat() : mesto("Novi Sad"), ulica("Bul. Oslobodjenja"), broj(1), godinaProizvodnje(2000){}

        void ukljuciGrejanje(){
            for(int i = 0; i < prostorije.size(); i++){
                prostorije[i]->grejanje(); // ukljucije grejanje u svakoj prostoriji
            }
        }

        void iskljuciGrejanje(){
            for(int i = 0; i < prostorije.size(); i++){
                prostorije[i]->hladjenje(); // ukljucuje hladjenje u svakoj prostoriji
            }
        }

        double prosecnaTemperatura(){

            double suma = 0;
            for(int i = 0; i < prostorije.size(); i++){
                suma += prostorije[i]->getTemperatura();
            }

            return suma / prostorije.size(); // vraca srednju vrednost
        }

        void dodajProstoriju(Prostorija* p){
            prostorije.push_back(p);
        }


};


#endif // STAMBENIOBJEKAT_H_INCLUDED
