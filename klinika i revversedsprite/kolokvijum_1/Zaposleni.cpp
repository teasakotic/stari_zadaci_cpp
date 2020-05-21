

#include "Zaposleni.hpp"

Zaposleni::Zaposleni(std::string ime, std::string prezime, std::string datumRodjenja, std::string sifra)
    : Osoba(ime, prezime, datumRodjenja), sifra{sifra}{}


std::string Zaposleni::getSifra(){ return this->sifra; }
void Zaposleni::setSifra(std::string sifra){ this->sifra = sifra; }

void Zaposleni::predstaviSe() const {
    std::cout << this->ime << " " << this->prezime << " " << this->sifra << std::endl;
}