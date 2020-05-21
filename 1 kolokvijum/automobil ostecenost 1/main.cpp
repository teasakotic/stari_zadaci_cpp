#include <iostream>
using namespace std;
#include "deo.h"
#include "automobil.h"
#include "tocak.h"
#include "kamion.h"
#include "motor.h"
// Ako imamo zvezdicu (pokazivac) onda se metoda poziva sa strelicom
// vector<Deo*> delovi;    delovi[i]->ispis();
// vector<Tocak> tockovi;  tockovi[i].ispis();
int main()
{
    Kamion k("Mercedes", "S");
    k.tehnickiPregled();
    k.vozi(100);

    Tocak t("Veliki", "Goodyear", 0);
    k.ubaciDeo(&t);
    Motor m("Nov", "NekiProizvodjac", 500);
    k.ubaciDeo(&m);
    k.tehnickiPregled();

    k.vozi(200);
    k.tehnickiPregled();

    if (k.ispravnost() == true){
       cout << "Kamion je ispravan" << endl;
    } else {
        cout << "Kamion nije ispravan" << endl;
    }

    k.vozi(2000);
    k.tehnickiPregled();

    if (k.ispravnost() == true){
       cout << "Kamion je ispravan" << endl;
    } else {
        cout << "Kamion nije ispravan" << endl;
    }
    return 0;
}
