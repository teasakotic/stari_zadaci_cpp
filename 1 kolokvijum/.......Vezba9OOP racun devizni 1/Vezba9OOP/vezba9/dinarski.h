#ifndef DINARSKI_H_INCLUDED
#define DINARSKI_H_INCLUDED
#include "racun.h"

class Dinarski:public Racun{
public:
    Dinarski(int brojRacuna, float stanjeRacuna):Racun(brojRacuna, stanjeRacuna){};

    void ispis(){
        cout<<getBrojRacuna()<<" | "<<getStanjeRacuna()<<endl;
    }

    void skidanjeSaRacuna(float x){
        if(x > getStanjeRacuna()){
            cout<<"Nema dovoljno sredstava na racunu"<<endl;
        }
        else{
            setStanjeRacuna(getStanjeRacuna()-x);
            cout<<"Sa racuna je skinuto "<<x<<" dinara!"<<endl;

        }
    }
};

#endif // DINARSKI_H_INCLUDED
