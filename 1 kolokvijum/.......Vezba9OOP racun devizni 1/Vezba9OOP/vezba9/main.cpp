#include <iostream>
#include "racun.h"
#include "dinarski.h"
#include "devizni.h"
#include "banka.h"
#include "erste.h"
using namespace std;

int main()
{
Banka * banka = new Erste("Erste");
Racun * dinarski = new Dinarski(1, 25000);
Racun * devizni = new Devizni(2, 50000);

banka->dodavanjeUvektor(dinarski);
banka->dodavanjeUvektor(devizni);

dinarski->skidanjeSaRacuna(5000);
devizni->skidanjeSaRacuna(100);
banka->ispisSvihRacuna();

}
