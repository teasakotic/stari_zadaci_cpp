#ifndef KUHINJA_H_INCLUDED
#define KUHINJA_H_INCLUDED

#include "prostorija.h"

class Kuhinja : public Prostorija {
public:
    const static string vrsta;
    Kuhinja(const string &opis, unsigned int godinaProizvodnje, double povrsina, double temeperatura);
    Kuhinja(istream &in);
    virtual string getVrsta() const;
    virtual void grejanje();
    virtual void hladjenje();
};

#endif // KUHINJA_H_INCLUDED
