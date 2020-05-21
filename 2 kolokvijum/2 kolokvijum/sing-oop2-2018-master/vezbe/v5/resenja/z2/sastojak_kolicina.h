#ifndef SASTOJAK_KOLICINA_H_INCLUDED
#define SASTOJAK_KOLICINA_H_INCLUDED

#include "sastojak.h"

class SastojakKolicina {
    private:
        Sastojak *sastojak;
        double kolicina;
    public:
        SastojakKolicina(Sastojak *sastojak, double kolicina) : sastojak(sastojak), kolicina(kolicina) {};
        Sastojak* getSastojak() {return sastojak;};
        void setSastojak(Sastojak *sastojak) {this->sastojak = sastojak;};
        double getKolicina() {return kolicina;};
        void setKolicina(double kolicina) {this->kolicina = kolicina;};
        double getEnergetskaVrednost() {return sastojak->getEnergetskaVrednost()/100 * kolicina;}
        double getCena() {return sastojak->getCena()/100 * kolicina;}
};

#endif // SASTOJAK_KOLICINA_H_INCLUDED
