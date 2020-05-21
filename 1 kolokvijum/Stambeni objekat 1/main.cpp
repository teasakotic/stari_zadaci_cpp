#include <iostream>
#include "zgrada.h"
using namespace std;

int main()
{

    Lift* l = new Lift("lift", 1999, 5.5, 20);
    Zgrada* z = new Zgrada(l);

    Prostorija* p1 = new Prostorija("soba1", 2000, 20.5, 25.5);
    Prostorija* p2 = new Prostorija("soba2", 2000, 15.0, 24.4);
    Prostorija* p3 = new Prostorija("soba3", 2000, 22.0, 23.3);
    Prostorija* p4 = new Prostorija("soba4", 2000, 10.0, 22.2);

    Kupatilo* k1 = new Kupatilo("kupatilo", 2000, 15.2, 20);
    Kuhinja* k2 = new Kuhinja("kuhinja", 2000, 12.2, 20);

    p1->postavitiTrenutnuTemperaturu(20);
    p2->postavitiTrenutnuTemperaturu(20);
    p3->postavitiTrenutnuTemperaturu(20);
    p4->postavitiTrenutnuTemperaturu(20);


    z->dodajProstoriju(p1);
    z->dodajProstoriju(p2);
    z->dodajProstoriju(p3);
    z->dodajProstoriju(p4);

    z->dodajProstoriju(k1);
    z->dodajProstoriju(k2);

    z->ispisi();

    z->ukljuciGrejanje();
    z->ukljuciGrejanje();
    z->ukljuciGrejanje();

    z->ispisi();

    z->iskljuciGrejanje();
    z->iskljuciGrejanje();

    z->ispisi();

    cout << endl << "Prosecna temperatura" << z->prosecnaTemperatura() << endl;

    return 0;
}
