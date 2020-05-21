#ifndef TASTATURA_H_INCLUDED
#define TASTATURA_H_INCLUDED
#include "deo.h"

class Tastatura : public Deo{
public:
    Tastatura(string nazivProizvodjaca, string nazivDela, float ostecenostDela):Deo(nazivProizvodjaca, nazivDela, ostecenostDela){
        this->nazivProizvodjaca = nazivProizvodjaca;
        this->nazivDela = nazivDela;
        this->ostecenostDela = ostecenostDela;
    }

    void ispis(){
        cout<<getNazivDela()<<"("<<getNazivProizvodjaca()<<"), pohabanost: "<<getOstecenostDela()<<endl;
    }

    bool ispravnost(){
        if(this->getOstecenostDela()<1000){
            return true;
        }
        else{
            return false;
        }
    }
};

#endif // TASTATURA_H_INCLUDED
