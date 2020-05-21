#ifndef KVARLJIVA_H_INCLUDED
#define KVARLJIVA_H_INCLUDED
#include "roba.h"

class Kvarljiva : public Roba{
public:
    float rokTrajanja;

    Kvarljiva(float rokTrajanja, string ime, float cena, float kolicina, string sifra):Roba(ime, cena, kolicina, sifra){
        this->rokTrajanja = rokTrajanja;
        this->cena = cena;
        this->kolicina = kolicina;
        this->sifra = sifra;
    }

    float getRokTrajanja(){
        return this->rokTrajanja;
    }

    void setRokTrajanja(float nRokTrajanja){
        this->rokTrajanja = nRokTrajanja;
    }

    void detalji(){
        if(getRokTrajanja()<=0){
            cout<<"Rok je istekao!"<<endl;
        }
        else{
            cout<<getIme()<<" | "<<getCena()<<" | "<<"Rok istice za: "<<getRokTrajanja()<<" dana!"<<endl;
        }

    }
};

#endif // KVARLJIVA_H_INCLUDED
