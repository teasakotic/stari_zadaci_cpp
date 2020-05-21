#include <iostream>
#include "osoba.h"
#include "zaposleni.h"
#include "medicinskiTehnicar.h"
#include "lekar.h"
#include "klinika1.h"
#include "osoba1.h"
using namespace std;

int main()
{
Klinika1* k = new Klinika1("NML");
Osoba* mt = new MedicinskiTehnicar("Laza", "Lazic", "20.7.1981.", "51464");
Osoba* l = new Lekar("Pera", "Peric", "8.2.1991.","93131");
Osoba* osoba1 = new Osoba1("Ilija", "Ilic", "5.9.1993.");
k->dodavanjeUVektor(mt);
k->dodavanjeUVektor(l);
k->dodavanjeUVektor(osoba1);
k->ispis();
}
