#include <iostream>
#include "deo.h"
#include "mis.h"
#include "tastatura.h"
#include "racunar.h"
#include "samsung123.h"
using namespace std;

int main()
{
    Deo * mis = new Mis("LG", "mis", 900);
    Deo * tastatura = new Tastatura("LG", "tastatura", 1000);

    Racunar * samsung123 = new Samsunc123("Samsung", "samsung123");
    samsung123->dodavanjeUvektor(mis);
    samsung123->dodavanjeUvektor(tastatura);
    cout<<samsung123->ispravnost()<<endl;
    samsung123->servis();
    //mis->ispis();
    //tastatura->ispis();
}
