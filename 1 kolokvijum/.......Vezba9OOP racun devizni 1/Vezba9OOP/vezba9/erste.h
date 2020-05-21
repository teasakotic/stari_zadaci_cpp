#ifndef ERSTE_H_INCLUDED
#define ERSTE_H_INCLUDED
#include "banka.h"

class Erste:public Banka{
public:
    Erste(string ime):Banka(ime){};

    void ispisSvihRacuna(){
        for(size_t i = 0; i<racuni.size(); i++){
            racuni[i]->ispis();
    }
    }
};

#endif // ERSTE_H_INCLUDED
