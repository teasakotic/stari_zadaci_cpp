#ifndef PRAVOUGAONIK_H_INCLUDED
#define PRAVOUGAONIK_H_INCLUDED

#include "oblik.h"

class Pravougaonik : public Oblik {
    private:
        double a;
        double b;
    public:
        Pravougaonik(double a, double b) : Oblik(), a(a), b(b) {};
        virtual double getA() {return a;}
        virtual double getB() {return b;}
        virtual double povrsina() {
            return a*b;
        }

        virtual double obim() {
            return 2*a+2*b;
        }

        virtual void iscrtavanje() {
            cout << "Pravougaonik, stranica a i b duzine " << a << " i " << b << endl;
        }
};

#endif // PRAVOUGAONIK_H_INCLUDED
