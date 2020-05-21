#ifndef MAGIC_CREATURE_H_INCLUDED
#define MAGIC_CREATURE_H_INCLUDED

#include <string>

//Zaglavlje sa definicijom i deklaracijom klase Creature.
#include "creature.h"

using namespace std;

class MagicCreature : public Creature { //MagicCreature nasledjuje klasu Creature.
                                        //Zbog kljucne reci publiic ispred naziva klase
                                        //sve naslednice klase MagicCreature kao i sama
                                        //klasa MagicCreature ce najvise imati public
                                        //pravo pristupa atributima. U slucaju da je
                                        //upotrebljena kljucna rec protected, public
                                        //atributi klase Creature bi bili vidljivi kao
                                        //protected atributi. Da je navedena kljucna rec
                                        //private, protected i public atributi bi bili
                                        //vidljivi kao private atributi.
    protected:
        double mp; //Atribut mp uvodi klasa MagicCreature.

    public:
        MagicCreature(double, double, double, string);
        double getMp() {return mp;}
        void setMp(double mp) {this->mp = mp;}
        string introduce();
        bool isAlive(); //Klasa MagicCreature mora implementirati metodu isAlive kako ne bi bila
                        //apstraktna klasa.
        void magicAttack(Creature &other);
};

#endif // MAGIC_CREATURE_H_INCLUDED
