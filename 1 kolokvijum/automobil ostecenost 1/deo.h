#ifndef DEO_H_INCLUDED
#define DEO_H_INCLUDED

#include <iostream>
using namespace std;

class Deo {
 protected:
     string nazivProizvodjaca;
     string nazivDela;
     double ostecenost;
 public:

    Deo(string np, string nd, double os) : nazivProizvodjaca(np), nazivDela(nd), ostecenost(os) {}

    virtual void ispis() = 0;

    virtual bool ispravnost() {
        if ( ostecenost < 1000)
            return true;
        else
            return false;
    }

    virtual void upotrebi(int brojPredjenihKilometara){
        ostecenost += brojPredjenihKilometara;
    }

};

#endif // DEO_H_INCLUDED
