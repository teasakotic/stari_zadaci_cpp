#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>

using namespace std;

class Creature;

class Item {
    protected:
        string name;
        string type;
    public:
        Item(string name) : name(name), type("item"){};
        virtual void use()=0;               //Iako obe metode imaju naziv use
        virtual void use(Creature &target); //one predstavljaju razlicite metode
                                            //jer se razlikuju po broju i tipu
                                            //parametara. Virtualne metode moraju biti
                                            //implementirane u klasa u kojima su deklarisane.
                                            //Metodu je neophodno proglasiti za virtualnu kako
                                            //bi se omogucilo polimorfno ponasanje metoda.
        virtual string getType() {return type;};
        virtual string getName() {return name;};
};

#endif // ITEM_H_INCLUDED
