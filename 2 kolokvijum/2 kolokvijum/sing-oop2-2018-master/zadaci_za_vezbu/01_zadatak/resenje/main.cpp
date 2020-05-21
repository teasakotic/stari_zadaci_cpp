#include <iostream>
#include <fstream>

#include "adresa.h"
#include "prostorija.h"
#include "kuhinja.h"
#include "kupatilo.h"
#include "zgrada.h"

using namespace std;

ostream& operator<<(ostream &out, const Adresa &adresa) {
    return out << adresa.mesto << ";" << adresa.ulica << ";" << adresa.broj;
}

ostream& operator<<(ostream &out, const Adresa *adresa) {
    return out << (*adresa);
}

ostream& operator<<(ostream &out, const Prostorija &prostorija) {
    out << prostorija.getVrsta() << ";" << prostorija.opis << ";";
    out << prostorija.godinaProizvodnje << ";" << prostorija.povrsina << ";";
    return out << prostorija.temperatura;
}

ostream& operator<<(ostream& out, const Prostorija *prostorija) {
    out << (*prostorija);
    return out;
}

ostream& operator<<(ostream& out, const StambeniObjekat &so) {
    out << so.adresa << endl;
    out << so.godinaProizvodnje;
    for(Prostorija* p : so.prostorije) {
        out << endl << p;
    }
    return out;
}

ostream& operator<<(ostream &out, const StambeniObjekat *so) {
    return out << (*so);
}

int main()
{
    Adresa *adresa = new Adresa("Novi Sad", "Bulevar Mihajla Pupina", "261a");
    Prostorija *trpezarija = new Prostorija("Trpezarija", 1976, 20, 20);
    Prostorija *spavacaSoba1 = new Prostorija("Spavaca soba", 1976, 14, 20);
    Prostorija *spavacaSoba2 = new Prostorija("Spavaca soba", 1976, 16, 20);
    Prostorija *dnevnaSoba = new Prostorija("Dnevna soba", 1976, 14, 20);
    Kupatilo *kupatilo = new Kupatilo("Kupatilo", 1976, 5, 20);
    Kuhinja *kuhinja = new Kuhinja("Kuhinja", 1976, 7, 20);

    Zgrada *stambenaZgrada = new Zgrada(adresa, 1976);
    stambenaZgrada->dodajProstoriju(spavacaSoba1);
    stambenaZgrada->dodajProstoriju(spavacaSoba2);
    stambenaZgrada->dodajProstoriju(dnevnaSoba);
    stambenaZgrada->dodajProstoriju(trpezarija);
    stambenaZgrada->dodajProstoriju(kupatilo);
    stambenaZgrada->dodajProstoriju(kuhinja);

    cout << "Prosecna temperatura: " << stambenaZgrada->izracunajProsecnuTemeperaturu() << endl;

    stambenaZgrada->grejanje();
    stambenaZgrada->grejanje();
    stambenaZgrada->grejanje();

    stambenaZgrada->hladjenje();
    stambenaZgrada->hladjenje();

    cout << "Prosecna temperatura: " << stambenaZgrada->izracunajProsecnuTemeperaturu() << endl;

    ofstream out("zgrada.txt");
    out << stambenaZgrada;
    out.close();

    //Definisanje delimitera za citanje
    const ctype<char>::mask* m = ctype<char>::classic_table();
    vector<ctype<char>::mask> newMask(m, m+ctype<char>::table_size);
    newMask[' '] ^= ctype_base::space;
    newMask[';'] |= ctype_base::space;
    ifstream in("zgrada.txt");
    //Podesavanje delimitera na toku.
    in.imbue(locale(in.getloc(), new ctype<char>(newMask.data())));
    Zgrada *novaZgrada = new Zgrada(in);
    in.close();
    cout << novaZgrada << endl;
    return 0;
}
