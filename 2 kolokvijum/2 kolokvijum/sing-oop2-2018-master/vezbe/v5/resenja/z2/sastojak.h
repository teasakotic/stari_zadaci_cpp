#ifndef SASTOJAK_H_INCLUDED
#define SASTOJAK_H_INCLUDED

#include <string>

using namespace std;

class Sastojak {
    private:
        string naziv;
        double energetskaVrednost;
        double cena;
    public:
        Sastojak(string naziv, double energetskaVrednost, double cena) : naziv(naziv),
                                                                         energetskaVrednost(energetskaVrednost),
                                                                         cena(cena) {};

        string getNaziv() {return naziv;};
        void setNaziv(string naziv) {this->naziv = naziv;};
        double getEnergetskaVrednost() {return energetskaVrednost;};
        void setEnergetskaVrednost(double energetskaVrednost) {this->energetskaVrednost = energetskaVrednost;};
        double getCena() {return cena;};
        void setCena(double cena) {this->cena = cena;};
};

#endif // SASTOJAK_H_INCLUDED
