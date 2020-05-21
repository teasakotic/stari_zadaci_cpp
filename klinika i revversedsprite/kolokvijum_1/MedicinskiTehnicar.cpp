

#include "MedicinskiTehnicar.hpp"

MedicinskiTehnicar::MedicinskiTehnicar(std::string ime, std::string prezime, std::string datumRodjenja, std::string sifra, std::string titula)
    : Zaposleni(ime, prezime, datumRodjenja, sifra), titula{titula}{}


MedicinskiTehnicar::~MedicinskiTehnicar(){}

std::string MedicinskiTehnicar::getTitula(){ return this->titula; }
void MedicinskiTehnicar::setTitula(std::string titula){ this->titula = titula; }

void MedicinskiTehnicar::predstaviSe() const {
    std::cout << this->ime << " " << this->prezime << " " << this->sifra << " " << this->titula << std::endl;
}