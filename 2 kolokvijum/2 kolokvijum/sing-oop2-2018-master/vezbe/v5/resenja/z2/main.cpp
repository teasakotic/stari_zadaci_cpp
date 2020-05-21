#include <iostream>

#include "sastojak.h"
#include "recept.h"

using namespace std;

int main()
{
    Sastojak *voda = new Sastojak("Voda", 0, 1);
    Sastojak *brasno = new Sastojak("Brasno", 1523, 5);
    Sastojak *kvasac = new Sastojak("Kvasac", 1360, 190);
    Sastojak *so = new Sastojak("So", 0, 5);

    Recept *hleb = new Recept("Hleb");
    hleb->addSastojak(voda, 200);
    hleb->addSastojak(kvasac, 10);
    hleb->addSastojak(brasno, 800);
    hleb->addSastojak(so, 3);
    hleb->ispisiRecept();

    return 0;
}
