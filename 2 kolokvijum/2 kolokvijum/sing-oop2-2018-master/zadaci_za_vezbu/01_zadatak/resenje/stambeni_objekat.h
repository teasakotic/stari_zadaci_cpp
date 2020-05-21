#ifndef STAMBENI_OBJEKAT_H_INCLUDED
#define STAMBENI_OBJEKAT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

#include "adresa.h"
#include "prostorija.h"
#include "kuhinja.h"
#include "kupatilo.h"
#include "lift.h"

using namespace std;

class StambeniObjekat {
protected:
    Adresa *adresa;
    int godinaProizvodnje;
    vector<Prostorija*> prostorije;

public:
    StambeniObjekat(Adresa *adresa, unsigned int godinaProizvodnje);
    StambeniObjekat(istream &in);
    virtual void dodajProstoriju(Prostorija* prostorija);
    virtual void ukljuciGrejanje(bool ukljuceno=true);
    virtual void iskljuciGrejanje(bool iskljuceno=true);
    virtual void grejanje();
    virtual void hladjenje();
    virtual double izracunajProsecnuTemeperaturu();

    friend ostream& operator<<(ostream &out, const StambeniObjekat &so);
    friend ostream& operator<<(ostream &out, const StambeniObjekat *so);
};

#endif // STAMBENI_OBJEKAT_H_INCLUDED
