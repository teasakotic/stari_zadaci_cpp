#ifndef KAMION_H_INCLUDED
#define KAMION_H_INCLUDED

class Kamion : public Automobil {
public:
    Kamion(string n, string m) : Automobil(n,m) { }
    virtual void ubaciDeo(Deo* d){
        delovi.push_back(d);
    }
};

#endif // KAMION_H_INCLUDED
