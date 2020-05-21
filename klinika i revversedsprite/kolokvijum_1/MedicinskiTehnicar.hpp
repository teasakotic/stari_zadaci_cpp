

#ifndef MEDICINSKI_TEHNICAR_H
#define MEDICINSKI_TEHNICAR_H

#include "Zaposleni.hpp"

class MedicinskiTehnicar : public Zaposleni {
    private:
        std::string titula;
    public:
        MedicinskiTehnicar(std::string ime, std::string prezime, std::string datumRodjenja, std::string sifra, std::string titula);
        ~MedicinskiTehnicar();
        std::string getTitula();
        void setTitula(std::string titula);
        virtual void predstaviSe() const override;


};


#endif // MEDICINSKI_TEHNICAR_H