#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Adresa{
    public:
        string mesto;
        string ulica;
        string broj;
};

class Prostorija{
    public:
        string opis;
        int godinaProizvodnje;
        float povrsina;

        virtual bool zaRenoviranje(int godina);
        virtual void grejanje();
        virtual void hladjenje();

    private:
        int temperatura;
};

class StambeniObjekat{
    public:
        Adresa adresa;
        int godinaProizvodnje;
        vector<Prostorija> prostorije;

        virtual void grejanje();
        virtual void hladjenje();

        virtual void zaRenoviranje();
}