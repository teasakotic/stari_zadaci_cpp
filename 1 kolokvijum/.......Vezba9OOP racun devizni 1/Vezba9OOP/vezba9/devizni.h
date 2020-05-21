#ifndef DEVIZNI_H_INCLUDED
#define DEVIZNI_H_INCLUDED
#include "racun.h"

class Devizni:public Racun{
public:
    string valuta = "EUR";

    Devizni(int brojRacuna, float stanjeRacuna):Racun(brojRacuna, stanjeRacuna){};

    float konvertovanje(){
        return getStanjeRacuna()/120;
    }

    void ispis(){
        cout<<getBrojRacuna()<<" | "<<konvertovanje()<<" | "<<valuta<<endl;
    }
//korisnik unosi eure
    void skidanjeSaRacuna(float x){
       if(x>konvertovanje()){
        cout<<"Nema dovoljno sredstava na racunu!"<<endl;
       }
       else{
           float r = konvertovanje()-x;
           setStanjeRacuna(r*120);
           cout<<"Sa vaseg racuna je skinuto "<<x<<valuta<<endl;
       }
    }




};

#endif // DEVIZNI_H_INCLUDED
