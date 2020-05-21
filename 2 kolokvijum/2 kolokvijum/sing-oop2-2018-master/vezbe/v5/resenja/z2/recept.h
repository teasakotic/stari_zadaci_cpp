#ifndef RECEPT_H_INCLUDED
#define RECEPT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

#include "sastojak.h"
#include "sastojak_kolicina.h"

using namespace std;

class Recept {
    private:
        string naziv;
        vector<SastojakKolicina*> sastojci;
    public:
        Recept(string naziv) : naziv(naziv) {};
        void addSastojak(Sastojak* sastojak, double kolicina) {
            sastojci.push_back(new SastojakKolicina(sastojak, kolicina));
        }
        void removeSastojak(size_t index) {
            if(index > 0 && index < sastojci.size()) {
                sastojci.erase(sastojci.begin()+index);
            }
        }
        double getEnergetskaVrednost() {
            double energetskaVrednost = 0;
            for(size_t i = 0; i < sastojci.size(); i ++) {
                energetskaVrednost += sastojci[i]->getEnergetskaVrednost();
            }
            return energetskaVrednost;
        }
        double getCena() {
            double cena = 0;
            for(size_t i = 0; i < sastojci.size(); i ++) {
                cena += sastojci[i]->getCena();
            }
            return cena;
        }
        void ispisiRecept() {
            cout << naziv << endl << endl;
            cout << "Sastojci: " << endl;
            for(size_t i = 0; i < sastojci.size(); i++) {
                cout << "\t- " << sastojci[i]->getSastojak()->getNaziv() << " (" << sastojci[i]->getKolicina() << "g)" << endl;
            }
            cout << endl;
            cout << "Energetska vrednost: " << getEnergetskaVrednost() << "KJ" << endl;
            cout << "Cena: " << getCena() << "RSD" << endl;
        }
};

#endif // RECEPT_H_INCLUDED
