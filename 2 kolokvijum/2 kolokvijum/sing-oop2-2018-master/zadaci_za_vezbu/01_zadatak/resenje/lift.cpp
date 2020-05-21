#include "lift.h"

const string Lift::vrsta = "LIFT";

Lift::Lift(const string &opis, unsigned int godinaProizvodnje, double povrsina, double temperatura):
    Prostorija(opis, godinaProizvodnje, povrsina, temperatura) {
}

Lift::Lift(istream &in) : Prostorija(in) {
}

string Lift::getVrsta() const{
    return vrsta;
}

void Lift::grejanje() {
}

void Lift::hladjenje() {
}
