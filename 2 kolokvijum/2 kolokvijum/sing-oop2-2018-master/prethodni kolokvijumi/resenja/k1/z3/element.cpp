#include "element.h"

Element::Element(int brojUlaza) {
    for(int i = 0; i < brojUlaza; i++) {
        ulazi.push_back(false);
    }
}

void Element::obavestiPovezane() {
    for(size_t i = 0; i < veze.size(); i++) {
        veze[i]->element->setUlaz(veze[i]->pin, izlaz);
    }
}

void Element::setUlaz(int pin, bool stanje) {
    if(ulazi[pin] != stanje) {
        ulazi[pin] = stanje;
        izracunaj();
    }
}

bool Element::getUlaz(int pin) {
    return ulazi[pin];
}

void Element::setIzlaz(bool noviIzlaz) {
    if(noviIzlaz != izlaz) {
        izlaz = noviIzlaz;
        obavestiPovezane();
    }
}

bool Element::getIzlaz() {
    return izlaz;
}

void Element::povezi(Element* element, int ulazniPin) {
    veze.push_back(new Veza(element, ulazniPin));
    element->setUlaz(ulazniPin, izlaz);
}
