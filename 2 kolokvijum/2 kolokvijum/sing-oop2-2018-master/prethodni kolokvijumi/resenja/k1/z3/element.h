#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include <vector>

#include "veza.h"

using namespace std;

class Veza;

class Element {
private:
    bool izlaz;
    vector<Veza*> veze;
protected:
    vector<bool> ulazi;
    virtual void obavestiPovezane();
public:
    Element(int brojUlaza=1);
    virtual void setUlaz(int pin, bool stanje);
    virtual bool getUlaz(int pin);
    virtual void setIzlaz(bool noviIzlaz);
    virtual bool getIzlaz();
    virtual void povezi(Element* element, int ulazniPin);
    virtual void izracunaj()=0;
};

#endif // ELEMENT_H_INCLUDED
