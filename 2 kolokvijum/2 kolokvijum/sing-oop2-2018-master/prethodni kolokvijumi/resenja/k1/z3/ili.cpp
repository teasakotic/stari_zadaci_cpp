#include "ili.h"

IliKolo::IliKolo(int brojUlaza) : Element(brojUlaza) {
    setIzlaz(false);
}

void IliKolo::izracunaj() {
    for(size_t i = 0; i < ulazi.size(); i++) {
        if(ulazi[i]) {
            setIzlaz(true);
            return;
        }
    }

    setIzlaz(false);
}
