#ifndef ZGRADA_H_INCLUDED
#define ZGRADA_H_INCLUDED

#include "stambeniObjekat.h"

class Zgrada : public StambeniObjekat {
private:
    Lift* lift;
public:
    Zgrada(Lift* l) : StambeniObjekat(), lift(l) {}

    double prosecnaTemperatura(){

            double suma = 0;
            for(int i = 0; i < prostorije.size(); i++){
                suma += prostorije[i]->getTemperatura();
            }

            suma+= lift->getTemperatura(); // dodamo i temperaturu lifta, posto se on ne nalazi u vektoru

            return suma / (prostorije.size() + 1); // vraca srednju vrednost, ovo +1 stoji tu zbog lifta, jer on nije u vektoru
    }

            // dodatna metoda, ne trazi se u zadatku, ali da mozemo da vidimo da li sve radi
        void ispisi(){

            cout << endl << endl;
            cout << "Zgrada: ";
            for(int i = 0; i < prostorije.size(); i++){
                prostorije[i]->ispisi();
            }

            lift->ispisi();
        }
};


#endif // ZGRADA_H_INCLUDED
