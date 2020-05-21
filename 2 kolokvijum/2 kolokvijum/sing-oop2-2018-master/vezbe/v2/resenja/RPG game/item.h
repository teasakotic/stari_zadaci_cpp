#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>

using namespace std;

class Creature;

class Item {
    protected:
        string name;
    public:
        Item(string name) : name(name){};
        void use();                 //Iako obe metode imaju naziv use
        void use(Creature &target); //one predstavljaju razlicite metode
                                    //jer se razlikuju po broju i tipu
                                    //parametara.
};

#endif // ITEM_H_INCLUDED
