#ifndef ELEKTRICNIKVAR_H_INCLUDED
#define ELEKTRICNIKVAR_H_INCLUDED

class ElektricniKvar : public Kvar {
public:
    ElektricniKvar(string n, string o, int d, bool t, int s) : Kvar(n,o,d,t,s) {}

};


#endif // ELEKTRICNIKVAR_H_INCLUDED
