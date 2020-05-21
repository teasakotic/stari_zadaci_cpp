#ifndef PETRUS_H_INCLUDED
#define PETRUS_H_INCLUDED
#include "poslasticarnica.h"

class Petrus:public Poslasticarnica{
public:
    Petrus(string ime):Poslasticarnica(ime){}

    void prikazSvih(){
        for(size_t i = 0; i<kolaci.size(); i++){
            kolaci[i]->prikaz();
        }
    }

    float prodaja(float kolicinaa){
        for(size_t i = 0; i<kolaci.size(); i++){
            kolaci[i]->umanji(kolicinaa);
        }
    }
};

#endif // PETRUS_H_INCLUDED
