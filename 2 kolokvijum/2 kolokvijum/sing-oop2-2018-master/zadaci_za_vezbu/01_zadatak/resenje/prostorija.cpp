#include "prostorija.h"

const string Prostorija::vrsta = "OBICNA";

Prostorija::Prostorija(const string &opis, unsigned int godinaProizvodnje,
                       double povrsina, double temeperatura) : opis(opis),
                       godinaProizvodnje(godinaProizvodnje), povrsina(povrsina),
                       temperatura(temeperatura) {
    grejanjeUkljuceno = true;
}

Prostorija::Prostorija(istream &in) {
    in >> opis >> godinaProizvodnje >> povrsina >> temperatura;
    grejanjeUkljuceno = true;
}

string Prostorija::getVrsta() const {
    return vrsta;
}

void Prostorija::postaviTrenutnuTemperaturu(double novaTemperatura) {
    temperatura = novaTemperatura;
}

double Prostorija::dobaviTemperaturu() {
    if(grejanjeUkljuceno) {
        return temperatura;
    }
    return 0;
}

void Prostorija::grejanje() {
    temperatura++;
}

void Prostorija::hladjenje() {
    temperatura--;
}

void Prostorija::ukljuciGrejanje(bool ukljuceno) {
    grejanjeUkljuceno = ukljuceno;
}

void Prostorija::iskljuciGrejanje(bool iskljuceno) {
    ukljuciGrejanje(!iskljuceno);
}
