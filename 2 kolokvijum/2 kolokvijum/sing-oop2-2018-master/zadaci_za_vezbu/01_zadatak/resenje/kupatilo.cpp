#include "kupatilo.h"

const string Kupatilo::vrsta = "KUPATILO";

Kupatilo::Kupatilo(const string &opis, unsigned int godinaProizvodnje, double povrsina, double temeperatura) :
    Prostorija(opis, godinaProizvodnje, povrsina, temeperatura) {

}

Kupatilo::Kupatilo(istream &in) : Prostorija(in) {
}

string Kupatilo::getVrsta() const{
    return vrsta;
}

void Kupatilo::grejanje() {
    temperatura += 3;
}

void Kupatilo::hladjenje() {
    temperatura -= 2;
}
