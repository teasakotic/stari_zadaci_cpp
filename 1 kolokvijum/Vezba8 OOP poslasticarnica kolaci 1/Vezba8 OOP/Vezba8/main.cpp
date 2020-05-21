#include <iostream>
#include "kolac.h"
#include "cokoKocka.h"
#include "saher.h"
#include "poslasticarnica.h"
#include "petrus.h"
using namespace std;

int main()
{
    Kolac * cokoKocka = new CokoKocka("Coko kocka", 250, 150);
    Kolac * saher = new Saher("Saher", 300, 200);
    Poslasticarnica * petrus = new Petrus("Petrus");

    petrus->dodavanjeUVektor(cokoKocka);
    petrus->dodavanjeUVektor(saher);


    petrus->prodaja(50);
    cokoKocka->umanji(50);
    saher->umanji(50);
    petrus->prikazSvih();

}
