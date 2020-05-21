#include <iostream>

#include "nili.h"

using namespace std;

int main()
{
    //Pogledati tabelu istinitosti: https://en.wikipedia.org/wiki/Flip-flop_(electronics)#SR_NOR_latch
    NiliKolo *kolo1 = new NiliKolo(2);
    NiliKolo *kolo2 = new NiliKolo(2);

    kolo1->povezi(kolo2, 0);
    kolo2->povezi(kolo1, 0);

    cout << "Reset stanje:" << endl;

    kolo1->setUlaz(1, true);
    kolo2->setUlaz(1, false);

    cout << " Q:\t" << kolo1->getIzlaz() << endl;
    cout << "!Q:\t" << kolo2->getIzlaz() << endl;

    cout << endl << "Set stanje:" << endl;

    kolo1->setUlaz(1, false);
    kolo2->setUlaz(1, true);

    cout << " Q:\t" << kolo1->getIzlaz() << endl;
    cout << "!Q:\t" << kolo2->getIzlaz() << endl;

    return 0;
}
