#include <iostream>
#include "sistem.h"
using namespace std;

int main()
{
    Sistem s;
    Tehnicar t(true, "Pera", "Peric", "mehanicar");
    Tehnicar t2(true, "Pera", "Peric", "elektricar");
    s.dodajTehnicara(&t);
    s.dodajTehnicara(&t2);

    Kvar k("mehanicki","nekiopis",23,false,2);
    Kvar k2("elektricni","nekiopis",23,false,2);

    s.dodajKvar(&k);
    s.dodajKvar(&k2);

    s.ispisiSistem();
    return 0;
}
