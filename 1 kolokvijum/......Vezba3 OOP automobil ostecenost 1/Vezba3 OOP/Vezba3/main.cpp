#include <iostream>
#include "deo.h"
#include "motor.h"
#include "menjac.h"
#include "automobil.h"
#include "audi.h"
using namespace std;

int main()
{
    Deo * motor = new Motor("volvo", "motor", 500);
    Deo * menjac = new Menjac("golf", "menjac", 900);

    Automobil * audi = new Audi("Audi", "A6");
    audi->dodavanje(motor);
    audi->dodavanje(menjac);
    audi->vozi(200);
    cout<<audi->ispravnost()<<endl;
    audi->tehnickiPregled();
    //motor->ispis();
    //menjac->ispis();

}
