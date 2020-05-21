#ifndef OSOBA_H
#define OSOBA_H



#include <string>
#include <iostream>

class Osoba {
    protected:
        std::string ime;
        std::string prezime;
        std::string datumRodjenja;
    public:
        Osoba(std::string ime, std::string prezime, std::string datumRodjenja);
        virtual ~Osoba() = default;
        std::string getIme();
        std::string getPrezime();
        std::string getDatumRodjenja();
        void setIme(std::string ime);
        void setPrezime(std::string prezime);
        void setDatumRodjenja(std::string datum);
        virtual void predstaviSe() const = 0;



};


#endif // OSOBA_H