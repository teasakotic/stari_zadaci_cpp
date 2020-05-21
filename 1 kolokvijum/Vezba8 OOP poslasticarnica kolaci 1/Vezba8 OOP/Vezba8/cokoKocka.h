#ifndef COKOKOCKA_H_INCLUDED
#define COKOKOCKA_H_INCLUDED
#include "kolac.h"

class CokoKocka:public Kolac{
public:
    CokoKocka(string naziv, float cena, float kolicina):Kolac(naziv, cena, kolicina){}

    void prikaz(){
        cout<<getNaziv()<<" | "<<getCena()<<" dinara | "<<getKolicina()<<" grama"<<endl;
    }

    float umanji(float k){
        setKolicina(getKolicina()-k);
    }
};

#endif // COKOKOCKA_H_INCLUDED
