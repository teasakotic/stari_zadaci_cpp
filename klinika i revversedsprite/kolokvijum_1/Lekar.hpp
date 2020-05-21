#ifndef LEKAR_H
#define LEKAR_H


#include "Zaposleni.hpp"

class Lekar : public Zaposleni {
     private:
        std::string titula;
    public:
        Lekar(std::string ime, std::string prezime, std::string datumRodjenja, std::string sifra, std::string titula);
        ~Lekar();
        std::string getTitula();
        void setTitula(std::string titula);
        virtual void predstaviSe() const override;
};


#endif // LEKAR_H