#include "nili.h"

NiliKolo::NiliKolo(int brojUlaza) : Element(brojUlaza) {
    ili = new IliKolo(brojUlaza);
    ne = new NeKolo();
    ili->povezi(ne, 0);
    setIzlaz(ne->getIzlaz());
}

void NiliKolo::izracunaj() {
    for(size_t i = 0; i < ulazi.size(); i++) {
        ili->setUlaz(i, ulazi[i]);
    }
    setIzlaz(ne->getIzlaz());
}
