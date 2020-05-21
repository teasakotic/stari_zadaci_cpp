#ifndef KLINIKA_H
#define KLINIKA_H

#include <vector>
#include <iostream>

#include "Zaposleni.hpp"


class Klinika {
    private:
        std::vector<Zaposleni*> zaposleni;
    public:
        Klinika();
        ~Klinika();
        void prikaziZaposlene() const;
        void dodajZaposlenog(Zaposleni *zaposleni);
        

};


#endif // KLINIKA_H