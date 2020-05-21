

#include "Klinika.hpp"

Klinika::Klinika(){}


void Klinika::prikaziZaposlene() const {
    for(auto radnik: zaposleni){
        radnik->predstaviSe();
        std::cout << "-------------------------------------------------------" << std::endl;
    }
}
void Klinika::dodajZaposlenog(Zaposleni *zaposleni){
    this->zaposleni.push_back(zaposleni);
}

Klinika::~Klinika(){
    for(auto radnik:zaposleni){
        delete radnik;
        radnik = nullptr;
    }
}