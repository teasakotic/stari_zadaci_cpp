#ifndef MENJAC_H_INCLUDED
#define MENJAC_H_INCLUDED
#include "deo.h"

class Menjac : public Deo{
public:
    Menjac(string nazivProizvodjaca, string nazivDela, float ostecenostDela):Deo(nazivProizvodjaca, nazivDela, ostecenostDela){
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

    void upotrebi(float predjeniPut){
        setOstecenostDela(getOstecenostDela()+predjeniPut);
    }
};

#endif // MENJAC_H_INCLUDED
