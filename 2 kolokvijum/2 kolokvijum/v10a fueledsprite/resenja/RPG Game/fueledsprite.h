#ifndef FUELEDSPRITE_H_INCLUDED
#define FUELEDSPRITE_H_INCLUDED
#include "sprite.h"

class FueledSprite:public Sprite{
public:
    float maxFuel;
    float fuel;

    FueledSprite(SpriteSheet *sheet, int width=64, int height=64, float maxFuel=60):Sprite(sheet, width, height){
        this->fuel = maxFuel;
        this->maxFuel = maxFuel;
    }

    void move(int dx, int dy) {
    spriteRect->x += dx;
    spriteRect->y += dy;
}


    void move() {
    if(state != 0 && this->fuel>0) {
        if(state & 2) {
            move(-2, 0);
        }
        if(state & 1) {
            move(2, 0);
        }
        if(state & 8) {
            move(0, -2);
        }
        if(state & 4) {
            move(0, 2);
        }

    }
    else{
        setState(0);
    }
}
};


#endif // FUELEDSPRITE_H_INCLUDED
