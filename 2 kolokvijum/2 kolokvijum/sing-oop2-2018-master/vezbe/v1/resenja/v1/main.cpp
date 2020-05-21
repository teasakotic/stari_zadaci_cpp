#include <iostream>

using namespace std;

//Zadatak 3:
//Funkcija povrsinaPravougaonika vraca vrednost
//tipa double i ima dva parametra tipa double.
double povrsinaPravougaonika(double a, double b) {
    //Povratna vrednost funkcije se racuna kao
    //proizvod duzina stranica pravougaonika.
    return a*b;
}

//Zadatak 5:
class Pravougaonik {
    private:
        double a;
        double b;
    public:
        Pravougaonik() {}; //Deklaracija i definicija konstruktora.
        Pravougaonik(double a, double b); //Deklaracija konstruktora.
        double getA() {return a;}; //Deklaracija i definicija getter metode za atribut a.
        double getB() {return b;}; //Deklaracija i definicija getter metode za atribut b.
        void setA(double a) {this->a = a;} //Deklaracija i definicija setter metode za atribut a.
                                           //Posto je u metodi vec upotrebljeno ime a za parametar
                                           //metode, neophodno je atribut a dobaviti preko this
                                           //pokazivaca. U protivnom bi se a u telu metode uvek
                                           //odnosilo na ime parametra metode a ne na atribut a.
        void setB(double newB) {b = newB;}; //Deklaracija i definicija setter metode za atribut a.
                                            //Ime parametra se razlikuje od imena atributa, takodje
                                            //u metodi se nigde ne pojavljuje ime koje bi preklopilo
                                            //ime atributa pa je zato atributu moguce pristupati
                                            //direktno bez navodjenja pokazivaca this.

        double povrsina(); //Deklaracija metode povrsina.
};

Pravougaonik::Pravougaonik(double a, double b) { //Implementacija konstruktora.
    this->a = a;
    this->b = b;
}

double Pravougaonik::povrsina() { //Implementacija metode povrsina.
    return a*b; //Pokazivac this se ne moran avoditi jer je jasno
                //da se imena a i b odnose na atribute klase a ne
                //na lokalne promenljive ili parametre metode.
}

//Zadatak 7:
//Po potrebi ovaj deo koda otkomentarisati.
/*
double Pravougaonik::povrsina() {
    return ::povrsinaPravougaonika(a, b); //Scope operator, ::, koristi se za pristup odredjenom
                                          //opsegu ili prostoru imena.
                                          //Kako prostor imena nije naveden bice dobavljena sva
                                          //imena iz globalnog opsega, ukljucujuci i funkciju
                                          //povrsinaPravougaonika.
}
*/

int main()
{
    //Zadatak 1:
    double povrsina = povrsinaPravougaonika(10, 2); //Poziv funkcije povrsina pravougaonika
                                                    //i smestanje rezultata u promenljivu
                                                    //tipa double pod nazivom povrsina.

    cout << povrsina << endl; //Ispis rezultata i novog reda na izlazni stream.
                              //Operatori << sluze za prosledjivnaje vrednosti
                              //u izlazni stream.

    //Zadatak 4:
    double niz[10] = {2, 5, 3, 1.2, 3, 4.2, 6.1, 1, -1, 20}; //Deklarisan i inicijalizovan
                                                             //niz od 10 elemenata tipa double.

    double prosek = 0;
    //Napomena: niz ne zna svoju duzinu.
    for(int i = 0; i < 10; i++) { //Petlja for se zapisuje u formatu: inicijalizacija; uslov, izraz.
        //Telo for petlje.
        prosek += niz[i]; //Skraceni zapis za: prosek = prosek + niz[i];
    }

    prosek /= 10; //Skraceni zapis za: prosek = prosek / 10;

    cout << prosek << endl;

    //Zadatak 5:
    Pravougaonik p(10, 2); //Instanciranje objekta klase Pravougaonik.
    cout << p.povrsina() << endl; //Ispis povratne vrednosti poziva metode povrsina
                                  //nad instancom klase Pravougaonik.
    return 0;
}
