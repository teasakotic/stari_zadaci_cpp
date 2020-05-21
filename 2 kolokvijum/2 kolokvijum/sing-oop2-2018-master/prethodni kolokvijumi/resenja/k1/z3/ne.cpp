#include "ne.h"

NeKolo::NeKolo() : Element() {
    setIzlaz(true);
}

void NeKolo::izracunaj() {
    setIzlaz(!ulazi[0]);
}
