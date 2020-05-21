#ifndef KRUG_H_INCLUDED
#define KRUG_H_INCLUDED

#include <iostream>
#include <cmath>

#include "oblik.h"

using namespace std;

class Krug : public Oblik {
    private:
        double r;
    public:
        Krug(double r) : Oblik(), r(r) {};
        virtual double getR() {return r;}
        virtual double povrsina() {
            return r*r*atan(1)*4; //Ne postoji konstanta za broj Pi.
                                  //Funkcija atan je inverzna funkcija
                                  //funkcije tan. Funkcija atan(1) vraca
                                  //vrednost Pi/4.
        }

        virtual double obim() {
            return 2*r*atan(1)*4;
        }

        virtual void iscrtavanje() {
            cout << "Krug poluprecnika " << r << endl;
        }
};

#endif // KRUG_H_INCLUDED
