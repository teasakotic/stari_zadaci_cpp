#include "event.h"

string Event::parseContent(string content, string key, string value) {
    size_t pos = content.find(key); //Metoda find pronalazi indeks prvog slova prve pojave zadatog podstringa.
                                    //Ukoliko podstring nije pronadjen metoda vraca vrednost npos konstante
                                    //iz klase string.
    if(pos != string::npos) {
        return content.replace(pos, key.size(), value); //Menja deo stringa od zadatog indeksa do zadate duzine
                                                        //prosledjenim stringom. Vraca se novi string.
    }

    //Ukoliko nije pronadjen zadati termin u stringu, vraca
    //se neizmenjen string.
    return content;
}
