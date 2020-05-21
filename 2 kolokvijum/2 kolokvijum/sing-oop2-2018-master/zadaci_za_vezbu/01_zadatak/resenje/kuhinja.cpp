#include "kuhinja.h"

const string Kuhinja::vrsta = "KUHINJA";

Kuhinja::Kuhinja(const string &opis, unsigned int godinaProizvodnje, double povrsina, double temeperatura):
    Prostorija(opis, godinaProizvodnje, povrsina, temeperatura) {
}

Kuhinja::Kuhinja(istream &in) : Prostorija(in) {
}

string Kuhinja::getVrsta() const {
    return vrsta;
}

void Kuhinja::grejanje() {
    temperatura += 2;
}

void Kuhinja::hladjenje() {
    temperatura -= 3;
}
