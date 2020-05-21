#include <iostream>
#include "roba.h"
#include "kvarljiva.h"
#include "nekvarljiva.h"
#include "magacin.h"
using namespace std;

int main()
{
    Roba * kvarljiva = new Kvarljiva(15, "Jogurt", 120, 950, "jogurt123");
    Roba * nekvarljiva = new Nekvarljiva("Casa", 250, 5, "casa123");

    //kvarljiva->detalji();
    //nekvarljiva->detalji();

    Magacin * mag = new Magacin("Maxi");
    mag->dodavanje(kvarljiva);
    mag->dodavanje(nekvarljiva);
    mag->ispis();
}
