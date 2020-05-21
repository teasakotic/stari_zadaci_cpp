#ifndef LIFT_H_INCLUDED
#define LIFT_H_INCLUDED

#include "prostorija.h"

class Lift : public Prostorija {
public:
    const static string vrsta;
    Lift(const string &opis, unsigned int godinaProizvodnje, double povrsina, double temperatura);
    Lift(istream &in);
    virtual string getVrsta() const;
    virtual void grejanje();
    virtual void hladjenje();
};

#endif // LIFT_H_INCLUDED
