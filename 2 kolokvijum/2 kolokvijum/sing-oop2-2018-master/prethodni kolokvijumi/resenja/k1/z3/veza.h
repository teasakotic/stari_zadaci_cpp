#ifndef VEZA_H_INCLUDED
#define VEZA_H_INCLUDED

#include "element.h"

class Element;

class Veza {
public:
    Element *element;
    int pin;

    Veza(Element* element, int pin);
};

#endif // VEZA_H_INCLUDED
