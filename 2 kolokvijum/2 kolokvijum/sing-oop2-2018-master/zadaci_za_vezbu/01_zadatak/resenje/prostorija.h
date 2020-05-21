#ifndef PROSTORIJA_H_INCLUDED
#define PROSTORIJA_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Prostorija {
protected:
    string opis;
    unsigned int godinaProizvodnje;
    double povrsina;
    double temperatura;
    bool grejanjeUkljuceno;
public:
    const static string vrsta;
    Prostorija(const string &opis, unsigned int godinaProizvodnje, double povrsina, double temperatura);
    Prostorija(istream &in);
    virtual string getVrsta() const;
    void postaviTrenutnuTemperaturu(double novaTemperatura);
    double dobaviTemperaturu();
    virtual void grejanje();
    virtual void hladjenje();
    virtual void ukljuciGrejanje(bool ukljuceno=true);
    virtual void iskljuciGrejanje(bool iskljuceno=true);

    friend ostream& operator<<(ostream& out, const Prostorija &prostorija);
    friend ostream& operator<<(ostream& out, const Prostorija *prostorija);
};

#endif // PROSTORIJA_H_INCLUDED
