#ifndef NILI_H_INCLUDED
#define NILI_H_INCLUDED

#include "element.h"
#include "ili.h"
#include "ne.h"

class NiliKolo : public Element {
protected:
    IliKolo *ili;
    NeKolo *ne;
public:
    NiliKolo(int brojUlaza);
    virtual void izracunaj();
};

#endif // NILI_H_INCLUDED
