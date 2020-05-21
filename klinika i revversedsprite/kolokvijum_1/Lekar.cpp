#include "Lekar.hpp"






Lekar::Lekar(std::string ime, std::string prezime, std::string datumRodjenja, std::string sifra, std::string titula)
    : Zaposleni(ime, prezime, datumRodjenja, sifra), titula{titula}{}


Lekar::~Lekar(){}

std::string Lekar::getTitula(){ return this->titula; }
void Lekar::setTitula(std::string titula){ this->titula = titula; }

void Lekar::predstaviSe() const {
    std::cout << this->ime << " " << this->prezime << " " << this->sifra << " " << this->titula << std::endl;
}