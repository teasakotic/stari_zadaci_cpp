#include <iostream>
#include "torta.h"
#include "cokoladna.h"
#include "vocna.h"
#include "magacin.h"
using namespace std;

int main()
{
    Torta * cokoladna = new Cokoladna("Cokoladna", 1500);
    //cokoladna->ispis();

    Torta * vocna = new Vocna("Vocna", 1700);
    //vocna->ispis();

    Magacin * magacin = new Magacin("miki");
    magacin->dodavanje(cokoladna);
    magacin->dodavanje(vocna);
    magacin->ispis();


}
