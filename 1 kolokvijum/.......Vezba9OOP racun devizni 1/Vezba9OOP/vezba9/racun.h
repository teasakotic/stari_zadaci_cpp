#ifndef RACUN_H_INCLUDED
#define RACUN_H_INCLUDED
#include <iostream>
using namespace std;

class Racun{
public:
    int brojRacuna;
    float stanjeRacuna;

    Racun(int brojRacuna, float stanjeRacuna){
        this->brojRacuna = brojRacuna;
        this->stanjeRacuna = stanjeRacuna;
    }

    int getBrojRacuna(){
        return this->brojRacuna;
    }

    float getStanjeRacuna(){
        return this->stanjeRacuna;
    }

    void setBrojRacuna(int nBrojRacuna){
        this->brojRacuna = nBrojRacuna;
    }

    void setStanjeRacuna(float nStanjeRacuna){
        this->stanjeRacuna = nStanjeRacuna;
    }

    virtual void ispis()=0;
    virtual void skidanjeSaRacuna(float x)=0;

 };

#endif // RACUN_H_INCLUDED
