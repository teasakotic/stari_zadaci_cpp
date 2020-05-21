#ifndef KVADRAT_H_INCLUDED
#define KVADRAT_H_INCLUDED
#include "oblik.h"

class Kvadrat:public Oblik{
public:
    //atributi
    float stranica_a;

    //konstruktor
    Kvadrat(float stranica_a){
        this->stranica_a = stranica_a;
    }

    //geteri
    float getStranica_a(){
        return stranica_a;
    }

    //seteri
    void setStranica_a(float nStranica_a){
        this->stranica_a = nStranica_a;
    }

    //metoda
    void iscrtaj(){
        cout<<"Ovo je kvadrat sa stranicom "<<getStranica_a()<<"cm i povrsinom "<<getStranica_a()*getStranica_a()<<"cm"<<endl;
    }

};

#endif // KVADRAT_H_INCLUDED
