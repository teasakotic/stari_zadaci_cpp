#ifndef ZAPOSLENI_H
#define ZAPOSLENI_H


#include "Osoba.hpp"

class Zaposleni : public Osoba {
    protected:
        std::string sifra;
    public:
        Zaposleni(std::string ime, std::string prezime, std::string datumRodjenja, std::string sifra);
        virtual ~Zaposleni() = default;
        std::string getSifra();
        void setSifra(std::string sifra);
        virtual void predstaviSe() const override = 0;


};




#endif // ZAPOSLENI_H