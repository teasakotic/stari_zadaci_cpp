#include "Osoba.hpp"

Osoba::Osoba(std::string ime, std::string prezime, std::string datumRodjenja)
    : ime{ime}, prezime{prezime}, datumRodjenja{datumRodjenja}{}


std::string Osoba::getIme(){ return this->ime; }
std::string Osoba::getPrezime(){ return this->prezime; }
std::string Osoba::getDatumRodjenja(){ return this->datumRodjenja; }

void Osoba::setIme(std::string ime){ this->ime = ime; }
void Osoba::setPrezime(std::string prezime){ this->prezime = prezime; }
void Osoba::setDatumRodjenja(std::string datum){ this->datumRodjenja = datum; }

void Osoba::predstaviSe() const {
    std::cout << this->ime << " " << this->prezime << std::endl;
}