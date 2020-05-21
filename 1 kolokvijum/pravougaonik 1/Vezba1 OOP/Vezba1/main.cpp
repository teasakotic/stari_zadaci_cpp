#include <iostream>
#include "oblik.h"
#include "kvadrat.h"
#include "pravougaonik.h"
#include "torba.h"
using namespace std;

int main()
{
    Oblik * kvadrat = new Kvadrat(5);
    //kvadrat->iscrtaj();

    Oblik * pravougaonik = new Pravougaonik(2, 5);
    //pravougaonik->iscrtaj();

    Torba * torba = new Torba("torbica");
    torba->dodavanje(kvadrat);
    torba->dodavanje(pravougaonik);
    torba->ispis();

}
