#ifndef KVADRAT_H_INCLUDED
#define KVADRAT_H_INCLUDED

#include "oblik.h"

class Kvadrat : public Oblik {
    private:
        double a;
    public:
        Kvadrat(double a) : Oblik(), a(a) {};
        virtual double getA() {return a;}
        virtual double povrsina() {
            return a*a;
        }

        virtual double obim() {
            return 4*a;
        }

        virtual void iscrtavanje() {
            cout << "Kvadrat, duzina stranice a: " << a << endl;
        }
};

#endif // KVADRAT_H_INCLUDED
