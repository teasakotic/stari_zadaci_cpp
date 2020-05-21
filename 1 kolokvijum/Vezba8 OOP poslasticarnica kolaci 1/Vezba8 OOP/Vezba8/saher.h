#ifndef SAHER_H_INCLUDED
#define SAHER_H_INCLUDED
#include "kolac.h"

class Saher:public Kolac{
public:
    Saher(string naziv, float cena, float kolicina):Kolac(naziv, cena, kolicina){}

    void prikaz(){
        cout<<getNaziv()<<" | "<<getCena()<<" dinara | "<<getKolicina()<<" grama"<<endl;
    }

    float umanji(float k){
        setKolicina(getKolicina()-k);
    }
};

#endif // SAHER_H_INCLUDED
