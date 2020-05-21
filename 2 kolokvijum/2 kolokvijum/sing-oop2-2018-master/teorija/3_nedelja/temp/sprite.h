#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

class Sprite {
    protected:
        int x;
        int y;
        string name;

    public:
        Sprite(string, int, int);
        int getX() {return x;}
        int getY() {return y;}
        string getName() {return name;}

        void setX(int aX);
        void setY(int aY);
        void setName(string);
};


#endif // SPRITE_H_INCLUDED
