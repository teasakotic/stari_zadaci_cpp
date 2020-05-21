#include <iostream>

#include "oblik.h"
#include "krug.h"
#include "pravougaonik.h"
#include "kvadrat.h"

using namespace std;

int main()
{
    Krug *krug = new Krug(3);
    Pravougaonik *pravougaonik = new Pravougaonik(3, 2);
    Kvadrat *kvadrat = new Kvadrat(2);

    krug->iscrtavanje();
    cout << "Obim kruga poluprecnika " << krug->getR() << " je: " << krug->obim() << endl;
    cout << "Povrsina kruga poluprecnika " << krug->getR() << " je: " << krug->povrsina() << endl << endl;

    pravougaonik->iscrtavanje();
    cout << "Obim pravougaonika stranica a i b duzine " << pravougaonik->getA() << " i " << pravougaonik->getB() << " je: " << pravougaonik->obim() << endl;
    cout << "Povrsina pravougaonika stranica a i b duzine " << pravougaonik->getA() << " i " << pravougaonik->getB() << " je: " << pravougaonik->povrsina() << endl << endl;

    kvadrat->iscrtavanje();
    cout << "Obim kvadrata cija je stranica a duzine " << kvadrat->getA() << " je: " << kvadrat->obim() << endl;
    cout << "Povrsina kvadrata cija je stranica a duzine " << kvadrat->getA() << " je: " << kvadrat->povrsina() << endl << endl;
    return 0;
}
