#include "tumble_event.h"

void TumbleEvent::execute(Creature &target) {
    mt19937 gen(time(0)); //Inicijalizacija generatora za seed vrednoscu,
                          //U ovom slucaju trenutno vreme.

    cout << title << endl << endl; // Ispis naslova dogadjaja.

    if(target.getItemCount() > 0) { //Ukoliko ciljna nema prazan inventar, pri izvrsenju dogadjaja
                                    //se nasumice uklanja jedna stavka inventara.
        uniform_int_distribution<int> uid(0, target.getItemCount()-1); //Distribucija za nasumican izbor brojeva.
        int itemIndex = uid(gen); //Nasumican izbor indeksa.

        //Pravljenje poruke za ispis.
        string modifiedContent = parseContent(content, "{TARGET}", target.getName());
        modifiedContent = parseContent(modifiedContent, "{ITEM}", target.getItem(itemIndex)->getName());
        modifiedContent = parseContent(modifiedContent, "{ITEM}", target.getItem(itemIndex)->getName());

        cout << modifiedContent << endl; //Ispis poruke.
        target.removeItem(itemIndex); //Uklanjanje stavke inventara.
    } else {
        uniform_real_distribution<double> urd(0.5, 3); //Distribucija za nasumican izbor brojeva.
        double lostHp = urd(gen); //Izbor nasumicne kolicine hp-a.
        //Generisanje poruke.
        string modifiedContent = parseContent("{TARGET} trips on a branch and falls to the ground and loses {AMOUNT} hp.", "{TARGET}", target.getName());
        stringstream strstream; //String tok se koristi za rad sa stringovima. Ponasa se isto kao cout tok.
        strstream << lostHp; //U tok se dodaje vrednost lostHp.
        modifiedContent = parseContent(modifiedContent, "{AMOUNT}", strstream.str()); //Metoda str nad stringstream objektom dobavlja string
                                                                                      //formiran na osnovu prethodno primenjenih operacija.
        cout << modifiedContent << endl; //Ispis poruke.
        target.setHp(target.getHp() - lostHp); //Smanjivanje hp-a za nasumice izabranu kolicinu.
    }
}
