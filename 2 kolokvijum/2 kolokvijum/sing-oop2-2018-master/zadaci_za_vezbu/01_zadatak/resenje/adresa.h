#ifndef ADRESA_H_INCLUDED
#define ADRESA_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Adresa {
public:
    string mesto;
    string ulica;
    string broj;
    Adresa(const string &mesto, const string &ulica, const string &broj);
    Adresa(istream &in);

    friend ostream& operator<<(ostream &out, const Adresa& adresa);
    friend ostream& operator<<(ostream &out, const Adresa* adresa);
};

#endif // ADRESA_H_INCLUDED
