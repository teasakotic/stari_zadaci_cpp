#ifndef MIS_H_INCLUDED
#define MIS_H_INCLUDED
#include "deo.h"

class Mis : public Deo{
public:
    Mis(string nazivProizvodjaca, string nazivDela, float ostecenostDela):Deo(nazivProizvodjaca, nazivDela, ostecenostDela){
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

#endif // MIS_H_INCLUDED
