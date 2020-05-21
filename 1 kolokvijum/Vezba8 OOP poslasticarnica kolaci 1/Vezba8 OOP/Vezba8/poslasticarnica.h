#ifndef POSLASTICARNICA_H_INCLUDED
#define POSLASTICARNICA_H_INCLUDED
#include "kolac.h"
#include <vector>

class Poslasticarnica{
public:
    string ime;
    vector <Kolac*> kolaci;

    Poslasticarnica(string ime){
        this->ime = ime;
    }

    string getIme(){
        return this->ime;
    }

    void setIme(string nIme){
        this->ime = nIme;
    }

    void dodavanjeUVektor(Kolac* ko){
        kolaci.push_back(ko);
    }

    virtual void prikazSvih()=0;
    virtual float prodaja(float kolicinaa)=0;
};

#endif // POSLASTICARNICA_H_INCLUDED
