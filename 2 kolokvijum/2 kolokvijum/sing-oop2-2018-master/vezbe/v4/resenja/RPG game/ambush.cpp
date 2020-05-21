#include "ambush.h"

void Ambush::execute(Creature &target) {
    //Kreiranje sadrzaja poruke.
    string modifiedContent = parseContent(content, "{TARGET}", target.getName());
    stringstream strstream;
    strstream << actors.size();
    modifiedContent = parseContent(modifiedContent, "{AMOUNT}", strstream.str());

    //Ispis naslova i poruke.
    cout << title << endl << endl;
    cout << modifiedContent << endl << endl;

    for(size_t i = 0; i < actors.size(); i++) {
        cout << actors[i]->getName() <<": " << actors[i]->introduce() << endl;
    }

    for(size_t i = 0; i < actors.size(); i++) {
        actors[i]->attack(target);
        target.attack(*actors[i]); //Posto su u kolekciju smesteni pokazivaci
                                   //a attack metoda zahteva referencu na instancu
                                   //klase creature, neophodno je prvo dereferencirati
                                   //pokazivac kako bi se dobavio objekat i potom
                                   //napravila referenca.
    }
}
