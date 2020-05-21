#ifndef ILI_H_INCLUDED
#define ILI_H_INCLUDED

#include "element.h"

class IliKolo : public Element {
public:
    IliKolo(int brojUlaza);
    virtual void izracunaj();
};

#endif // ILI_H_INCLUDED
