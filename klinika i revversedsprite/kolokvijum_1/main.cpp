


#include "Klinika.hpp"
#include "Zaposleni.hpp"
#include "MedicinskiTehnicar.hpp"
#include "Lekar.hpp"


int main(){
    Klinika *klinika = new Klinika();

    Zaposleni *lekar = new Lekar("Marko", "Markovic", "01/02/1990", "21930213", "Dr.");
    Zaposleni *lekar2 = new Lekar("Stefan", "Stefanovic", "01/02/1985", "8932981", "Dr.spec.");
    Zaposleni *lekar3 = new Lekar("Mladen", "Mladenovic", "10/04/1975", "74218721478", "Dr.");
    Zaposleni *tehnicar = new MedicinskiTehnicar("Lazar", "Lazarovic", "05/12/1983", "8513289A", "Med.teh");
    Zaposleni *tehnicar2 = new MedicinskiTehnicar("Miso", "Misic", "24/11/1991", "21315923", "Med.teh");
    Zaposleni *tehnicar3 = new MedicinskiTehnicar("Todor", "Todorovic", "28/06/1979", "28193HASD", "Med.teh");


    klinika->dodajZaposlenog(lekar);
    klinika->dodajZaposlenog(lekar2);
    klinika->dodajZaposlenog(lekar3);
    klinika->dodajZaposlenog(tehnicar);
    klinika->dodajZaposlenog(tehnicar2);
    klinika->dodajZaposlenog(tehnicar3);


    klinika->prikaziZaposlene();



    delete klinika;
    klinika = nullptr;


    return 0;
}