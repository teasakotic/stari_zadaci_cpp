#include "zgrada.h"

Zgrada::Zgrada(Adresa *adresa, unsigned int godinaProizvodnje) :
    StambeniObjekat(adresa, godinaProizvodnje) {
    dodajProstoriju(new Lift("lift", godinaProizvodnje, 4, 0));
}

Zgrada::Zgrada(istream &in) : StambeniObjekat(in) {
}
