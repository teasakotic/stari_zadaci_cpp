#ifndef ZGRADA_H_INCLUDED
#define ZGRADA_H_INCLUDED

#include <istream>

#include "stambeni_objekat.h"
#include "lift.h"

using namespace std;

class Zgrada : public StambeniObjekat {
public:
    Zgrada(Adresa* adresa, unsigned int godinaProizvodnje);
    Zgrada(istream &in);
};

#endif // ZGRADA_H_INCLUDED
