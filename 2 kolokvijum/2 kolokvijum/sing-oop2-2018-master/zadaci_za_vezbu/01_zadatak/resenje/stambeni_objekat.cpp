#include "stambeni_objekat.h"

StambeniObjekat::StambeniObjekat(Adresa* adresa, unsigned int godinaProizvodnje) {
    this->adresa = adresa;
    this->godinaProizvodnje = godinaProizvodnje;
}

StambeniObjekat::StambeniObjekat(istream& in){
    adresa = new Adresa(in);
    in >> godinaProizvodnje;
    string vrsta;
    Prostorija *p;
    while(!in.eof()) {
    in >> vrsta;
        if(vrsta == "LIFT") {
            p = new Lift(in);
        } else if(vrsta == "KUHINJA") {
            p = new Kuhinja(in);
        } else if(vrsta == "KUPATILO") {
            p = new Kupatilo(in);
        } else {
            p = new Prostorija(in);
        }
        prostorije.push_back(p);
    }
}

void StambeniObjekat::dodajProstoriju(Prostorija *prostorija) {
    prostorije.push_back(prostorija);
}

void StambeniObjekat::ukljuciGrejanje(bool ukljuceno) {
    for(size_t i = 0; i < prostorije.size(); i++) {
        prostorije[i]->ukljuciGrejanje(ukljuceno);
    }
}

void StambeniObjekat::iskljuciGrejanje(bool iskljuceno) {
    for(Prostorija* p : prostorije) {
        p->iskljuciGrejanje(iskljuceno);
    }
}

void StambeniObjekat::grejanje() {
    for(Prostorija* p : prostorije) {
        p->grejanje();
    }
}

void StambeniObjekat::hladjenje() {
    for(size_t i = 0; i < prostorije.size(); i++) {
        prostorije[i]->hladjenje();
    }
}

double StambeniObjekat::izracunajProsecnuTemeperaturu() {
    double suma = 0;
    for(size_t i = 0; i < prostorije.size(); i++) {
        suma += prostorije[i]->dobaviTemperaturu();
    }

    if(prostorije.size() > 0) {
        return suma/prostorije.size();
    }
    return 0;
}
