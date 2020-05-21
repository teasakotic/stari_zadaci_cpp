#ifndef KUPATILO_H_INCLUDED
#define KUPATILO_H_INCLUDED

#include "prostorija.h"

class Kupatilo : public Prostorija {
public:
    const static string vrsta;
    Kupatilo(const string &opis, unsigned int godinaProizvodnje, double povrsina, double temeperatura);
    Kupatilo(istream &in);
    virtual string getVrsta() const;
    virtual void grejanje();
    virtual void hladjenje();
};

#endif // KUPATILO_H_INCLUDED
